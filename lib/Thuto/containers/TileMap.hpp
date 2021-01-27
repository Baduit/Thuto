#pragma once

namespace thuto
{

/* class SquareMapInitializer
{
	public:
		void	operator()(Vector2D<Tile>& tiles) const;
	
	private:
		bool	is_top_border(const Tile& tile) const;
		bool	is_down_border(const Tile& tile, PosInt max_y) const;
		bool	is_left_border(const Tile& tile) const;
		bool	is_right_border(const Tile& tile, PosInt max_x) const;
};

class Map
{
	public:
		using TilesConnexionsInitializer = std::function<void (Vector2D<Tile>&)>;

	public:
		Map() = default;

		Map(const Map&) = delete;
		Map& operator=(const Map&) = delete;

		Map(Map&&) = default;
		Map& operator=(Map&&) = default;

		void load(std::string_view filename);

		std::string_view	get_name() const { return _name; }

		Tile&			operator[](Position2D pos) { return _tiles[pos]; }
		const Tile&		operator[](Position2D pos) const { return _tiles[pos]; }

		Tile&			operator()(std::size_t x, std::size_t y) { return _tiles(x, y); }
		const Tile&		operator()(std::size_t x, std::size_t y) const { return _tiles(x, y); }

		const Size2D&			get_size() const { return _tiles.get_size(); }
		const Vector2D<Tile>&	get_2D_container() const { return _tiles; }

		bool is_in_map(const Position2D& pos) const;

	private:
		std::string		_name = "NO_MAP";
		Vector2D<Tile>	_tiles;
};

void	Map::load(std::string_view filename)
{

	std::optional<std::string> file_content = File::readAllContent(filename);
	if (!file_content)
		throw std::runtime_error("Error while reading map file");

	auto json_object = json::parse(*file_content);

	if (json_object.at("map").size() != json_object.at("size").at("x").get<std::size_t>() * json_object.at("size").at("y").get<std::size_t>())
		throw std::runtime_error("Map Size does not match");

	_name = json_object.at("name").get<std::string>();
	_tiles.resize(json_object.at("size").at("x").get<std::size_t>(), json_object.at("size").at("y").get<std::size_t>());
	for (std::size_t i = 0; i < _tiles.get_container().size(); ++i)
	{
		auto tile_type = magic_enum::enum_cast<TileType>(json_object.at("map")[i].get<std::string>());
		if (!tile_type)
			throw std::runtime_error("Unknown tyle type in map");
		_tiles.get_container()[i].type = *tile_type;
		_tiles.get_container()[i].pos.x = i % _tiles.get_size().x;
		_tiles.get_container()[i].pos.y = i / _tiles.get_size().x;
	}


	SquareMapInitializer()(_tiles);
}

bool Map::is_in_map(const Position2D& pos) const
{
	return _tiles.is_in_map(pos);
}

void	SquareMapInitializer::operator()(Vector2D<Tile>& tiles) const
{
	for (auto& tile: tiles.get_container())
	{
		if (!is_top_border(tile))
			tile.adj_tiles.push_back(&tiles[{tile.pos.x, tile.pos.y - 1}]);
		if (!is_down_border(tile, tiles.get_size().y))
			tile.adj_tiles.push_back(&tiles[{tile.pos.x, tile.pos.y + 1}]);
		if (!is_left_border(tile))
			tile.adj_tiles.push_back(&tiles[{tile.pos.x - 1, tile.pos.y}]);
		if (!is_right_border(tile, tiles.get_size().x))
			tile.adj_tiles.push_back(&tiles[{tile.pos.x + 1, tile.pos.y}]);
	}
}

bool	SquareMapInitializer::is_top_border(const Tile& tile) const
{
	if (tile.pos.y == 0)
		return true;
	return false;
}

bool	SquareMapInitializer::is_down_border(const Tile& tile, PosInt max_y) const
{
	if (tile.pos.y >= max_y - 1)
		return true;
	return false;
}

bool	SquareMapInitializer::is_left_border(const Tile& tile) const
{
	if (tile.pos.x == 0)
		return true;
	return false;
}

bool	SquareMapInitializer::is_right_border(const Tile& tile, PosInt max_x) const
{
	if (tile.pos.x >= max_x - 1)
		return true;
	return false;
} */

} // namespace thuto