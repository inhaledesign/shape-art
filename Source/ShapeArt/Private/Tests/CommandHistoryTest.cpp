#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "Commands/CommandHistory.h"
#include "Commands/CanvasCommand.h"
#include "Tests/MockCanvasCommand.h"


BEGIN_DEFINE_SPEC(FCommandHistoryTest, "ShapeArt.CommandHistory", EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter )
    ICanvasCommand* Command1 { nullptr };
    ICanvasCommand* Command2 { nullptr };
    ICanvasCommand* Command3 { nullptr };
    UCommandHistory* History { nullptr };

    void TestUndoCount(int ExpectedCount) { TestEqual("Undo count", History->UndoCount(), ExpectedCount); }

    void TestRedoCount(int ExpectedCount) { TestEqual("Redo count", History->RedoCount(), ExpectedCount); }

    void TestCommandsSame(ICanvasCommand* Actual, ICanvasCommand* Expected) { TestEqual("Command address", Actual, Expected); }
    
END_DEFINE_SPEC(FCommandHistoryTest)

void FCommandHistoryTest::Define() {

    BeforeEach([this]() {
        Command1 = NewObject<UMockCanvasCommand>();
        Command2 = NewObject<UMockCanvasCommand>();
        Command3 = NewObject<UMockCanvasCommand>();
        History = NewObject<UCommandHistory>();
    });

    It("Post", [this]() {
        for(int i = 1; i <= 10; i++) {
            History->Post(Command1);
            TestUndoCount(i);
            TestRedoCount(0);
        }
    });

    It("Undo", [this]() {
        ICanvasCommand* UndoCommand { nullptr };
        History->Post(Command1);
        History->Post(Command2);
        History->Post(Command3);

        UndoCommand = History->Undo();
        TestUndoCount(2);
        TestRedoCount(1);
        TestCommandsSame(UndoCommand, Command3);

        UndoCommand = History->Undo();
        TestUndoCount(1);
        TestRedoCount(2);
        TestCommandsSame(UndoCommand, Command2);

        UndoCommand = History->Undo();
        TestUndoCount(0);
        TestRedoCount(3);
        TestCommandsSame(UndoCommand, Command1);
    });

    It("Redo", [this]() {
        ICanvasCommand* RedoCommand { nullptr };
        History->Post(Command1);
        History->Post(Command2);
        History->Post(Command3);
        History->Undo();
        History->Undo();
        History->Undo();

        RedoCommand = History->Redo();
        TestUndoCount(1);
        TestRedoCount(2);
        TestCommandsSame(RedoCommand, Command1);
        
        RedoCommand = History->Redo();
       TestUndoCount(2);
        TestRedoCount(1);
        TestCommandsSame(RedoCommand, Command2);
        
        RedoCommand = History->Redo();
       TestUndoCount(3);
        TestRedoCount(0);
        TestCommandsSame(RedoCommand, Command3);
    });

    It("Redo clears when command posted", [this]() {
        History->Post(Command1);
        History->Post(Command2);
        History->Post(Command3);
        History->Undo();
        History->Undo();
        History->Undo();
        History->Post(Command3);

        TestRedoCount(0);
    });

    It("Undo at history start returns null", [this]() {
        ICanvasCommand* UndoCommand { History->Undo() };
        TestNull("Command address", UndoCommand);
    });

    It("Redo at history end returns null", [this]() {
        ICanvasCommand* RedoCommand { History->Redo() };
        TestNull("Command address", RedoCommand);
    });

}