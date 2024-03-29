
# include "../../includes/header.hpp"

/* ************************************************************************** */
/*                                                                            */
/*   CONSTRUCTEUR															  */
/*                                                                            */
/* ************************************************************************** */
Data::Data(void)
{
	int	n1;	// n1 and n2 defines a link between these nodes
	int	n2;	//
	int	ei;	// the index of a gateway node

	cin >> n >> l >> e; cin.ignore();

	for (int i = 0; i < n; i++)
		vertices.push_back(Vertex(i));

	for (int i = 0; i < l; i++)
	{
		cin >> n1 >> n2; cin.ignore();
		vertices[n1].edges.push_back(pair<int, Vertex*>(1, &(vertices[n2]) ));
		vertices[n2].edges.push_back(pair<int, Vertex*>(1, &(vertices[n1]) ));
	}
	for (int i = 0; i < e; i++)
	{
		cin >> ei; cin.ignore();
		vertices[ei].gateway = 1;
		gateways_index.push_back(ei);
	}
}

/*   COPY CONSTRUCTEUR   **************************************************** */

Data::Data(const Data &src)
{
	(void)src;
}

/* ************************************************************************** */
/*                                                                            */
/*   DESTRUCTEUR															  */
/*                                                                            */
/* ************************************************************************** */
Data::~Data(void)
{
}

/* ************************************************************************** */
/*                                                                            */
/*   OPÉRATEUR																  */
/*                                                                            */
/* ************************************************************************** */

/*   OPÉRATEUR INTERNE   **************************************************** */

/*   OPÉRATEUR EXTERNE   **************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*   MÉTHODE																  */
/*                                                                            */
/* ************************************************************************** */

/*   MÉTHODE PUBLIC   ******************************************************* */

/*   MÉTHODE PRIVATE   ****************************************************** */

/* ************************************************************************** */
