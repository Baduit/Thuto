#include <boost/ut.hpp>
#include <Thuto/containers/Vector2D.hpp>

using namespace boost::ut;

int main()
{
	"basic"_test =
		[]()
		{
			thuto::Vector2D<int> v(3, 3);

			v.at({0, 0}) = 1;
			v.at({1, 0}) = 2;
			v.at({0, 1}) = 3;

			expect(v.at({0, 0}) == 1) << "Fist case";
			expect(v.get_container()[0] == 1) << "Fist case";

			expect(v.at({1, 0}) == 2) << "2nd case";
			expect(v.get_container()[1] == 2) << "2nd case";

			expect(v.at({0, 1}) == 3) << "Fist case of 2nd line";
			expect(v.get_container()[3] == 3) << "Fist case of 2nd line";


			std::vector<int> expected_vector =
				{
					1, 2, 0,
					3, 0, 0,
					0, 0, 0
				};

			expect(v.get_container() == expected_vector) << "Check the container has the right content";

			auto first_line = v.get_line(0);
			expect((first_line.size() == 3) >> fatal);
			expect(first_line[0] == 1);
			expect(first_line[1] == 2);
			expect(first_line[2] == 0);

			auto second_line = v.get_line(1);
			second_line[1] = 4;
			expect((second_line.size() == 3) >> fatal);
			expect(second_line[0] == 3);
			expect(second_line[1] == 4);
			expect(second_line[2] == 0);

			const auto& cv = v;
			auto const_second_line = cv.get_line(1);
			expect((const_second_line.size() == 3) >> fatal);
			expect(const_second_line[0] == 3);
			expect(const_second_line[1] == 4);
			expect(const_second_line[2] == 0);


			//auto first_column = v.get_column(0);
		};
}