// AUTHOR: NA
// DATE: 02/13/17
// DESC: Unit testing template file
// FILE: unit_test_template.cpp

#include <iostream>
#include <vector>
#include <string>
#include "gtest/gtest.h"
#include "../FOL/Atom.h"

using namespace ::testing;

class TestFOLAtom : public ::testing::Test{
        protected:
	std::vector<AtomType> at;
	Atom *test_atom_pnt = nullptr;

            virtual void SetUp(){
                at.push_back(AtomType::FUNCTION);
		at.push_back(AtomType::PREDICATE);
		at.push_back(AtomType::OPERATOR);
		at.push_back(AtomType::RELATION);
		at.push_back(AtomType::CONSTANT); 
		at.push_back(AtomType::OBJECT);

		test_atom_pnt = new Atom("test_atom", at[0]);
            }
            virtual void TearDown(){

            }                                              
};

// Tests are detected
TEST_F(TestFOLAtom, Detected){
    std::cout << "TestFOLAtom suite detected" << std::endl;
}

// Confirm atom types
TEST_F(TestFOLAtom, AtomType){
	EXPECT_EQ(AtomType::FUNCTION ,at[0]);
	EXPECT_EQ(AtomType::PREDICATE ,at[1]);
	EXPECT_EQ(AtomType::OPERATOR ,at[2]);
	EXPECT_EQ(AtomType::RELATION ,at[3]);
	EXPECT_EQ(AtomType::CONSTANT ,at[4]);
	EXPECT_EQ(AtomType::OBJECT ,at[5]);
}
// Test Atom constructor
TEST_F(TestFOLAtom, AtomConstructor){
	EXPECT_EQ(test_atom_pnt->name, "test_atom");
	EXPECT_EQ(test_atom_pnt->type, at[0]);
}

// Tests are completed
TEST_F(TestFOLAtom, Completed){
    std::cout << "TestFOLAtom suite completed" << std::endl;
}

// Test template
TEST_F(TestFOLAtom, Template){

}

