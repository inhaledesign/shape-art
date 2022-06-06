#include "PolygonSketch.h"
#include "gtest/gtest.h"


class PolygonSketchTest : public ::testing::Test {
protected:
	PolygonSketch Polygon {};
};

class PolygonSketchParameterizedTest : public PolygonSketchTest, public ::testing::WithParamInterface<int> {
protected: 
	void SetUp() override {
		Polygon = PolygonSketch { GetParam() };
	}
};

TEST_P(PolygonSketchParameterizedTest, Size) {
	int ExpectedSize = GetParam();
	EXPECT_EQ(Polygon.GetSize(), ExpectedSize) << "Polygon has wrong size";
	EXPECT_EQ(Polygon.GetVertices().Num(), ExpectedSize) << "Vertices has wrong size";
}

TEST_F(PolygonSketchTest, SetAndGetVertices) {
	Polygon  = PolygonSketch(3);
	Polygon.SetVertex(0, 1.0, 2.0);
	Polygon.SetVertex(1, 3, 4);
	Polygon.SetVertex(2, 5, 6);
	FVector Vertex0 = Polygon.GetVertex(0);
	FVector Vertex1 = Polygon.GetVertex(1);
	FVector Vertex2 = Polygon.GetVertex(2);
	EXPECT_DOUBLE_EQ(Vertex0.X, 1.0);
	EXPECT_DOUBLE_EQ(Vertex0.Y, 2.0);
	EXPECT_DOUBLE_EQ(Vertex0.Z, 0.0); // Z coordinates should always be zero
	EXPECT_DOUBLE_EQ(Vertex1.X, 3.0);
	EXPECT_DOUBLE_EQ(Vertex1.Y, 4.0);
	EXPECT_DOUBLE_EQ(Vertex1.Z, 0.0);
	EXPECT_DOUBLE_EQ(Vertex2.X, 5.0);
	EXPECT_DOUBLE_EQ(Vertex2.Y, 6.0);
	EXPECT_DOUBLE_EQ(Vertex2.Z, 0.0);
}

TEST_F(PolygonSketchTest, VerticesNotSameRef) {
	Polygon = PolygonSketch { 3 };
	FVector Vertex0 { Polygon.GetVertex(0) };
	FVector Vertex1 { Polygon.GetVertex(1) };
	FVector Vertex2 { Polygon.GetVertex(2) };
	EXPECT_NE(&Vertex0, &Vertex1);
	EXPECT_NE(&Vertex0, &Vertex2);
	EXPECT_NE(&Vertex1, &Vertex2);
}

INSTANTIATE_TEST_SUITE_P(ValidSizeParams, PolygonSketchParameterizedTest, testing::Values
	(3, 4, 5, 10000, 100000)
);