#pragma once

namespace thuto
{

/* template <typename Card>
class Deck
{
	public:
		std::size_t	get_size() const
		{
			return _container.size();
		}

		void add_back(const Card& c)
		{
			_container.push_back(c);
		}

		void add_back(Card&& c)
		{
			_container.push_back(std::move(c));
		}

		void shuffle()
		{
			static auto rng = std::default_random_engine(static_cast<unsigned int>(std::time(nullptr)));
			std::shuffle(_container.begin(), _container.end(), rng);
		}

		const Card&	see_top() const
		{
			return _container.front();
		}

		Card draw()
		{
			Card c = _container.front();
			_container.erase(_container.begin());
			return c;
		}

		std::vector<Card> draw(std::size_t n)
		{
			std::vector<Card> cards;
			cards.reserve(n);
			std::for_each_n(_container.begin(), n, [&](auto&& c) { cards.push_back(std::move(c)); });
			_container.erase(_container.begin(), _container.begin() + n);
			return cards;
		}

		auto	begin()	{ return _container.begin(); }
		auto	cbegin() const { return _container.cbegin(); }
		auto	end() { return _container.end(); }
		auto	cend() const { return _container.cend(); }

		auto	rbegin()	{ return _container.rbegin(); }
		auto	crbegin() const { return _container.crbegin(); }
		auto	rend() { return _container.rend(); }
		auto	crend() const { return _container.crend(); }

	private:
		std::vector<Card> _container;
}; */

} // namespace thuto