#include<iostream>
#include<string>
#include<iterator>
#include<list>
#include<set>
#include<map>
#include<algorithm>

/*-----------use list---------------------------------*/
void output(int n)
{
	std::cout << n << " ";
}

void use_list()
{
	using namespace std;
	list<int> one;
	list<int>::iterator pr;
	int stuff[] = { 1,2,2,4,5 };
	one.insert(one.begin(), stuff, stuff + 5);
	//for (pr = one.begin(); pr != one.end(); pr++)
	//output(*pr);
	//cout << endl;
	for_each(one.begin(), one.end(), output);
	cout << endl;
	//one.remove(2);
	one.unique();
	for_each(one.begin(), one.end(), output);
	cout << endl;

	list<int> two;
	int stu[] = { 1,2,3,8 };
	two.insert(two.begin(), stu, stu + 4);

	one.merge(two);
	for_each(one.begin(), one.end(), output);
}
/*-------------use set-------------------------*/
void use_set()
{
	using namespace std;
	const int N = 6;
	//key and value are equl for set
	//union, difference, intersection, insert 
	//排序决定了插入的位置，所以insert只有一个参数
	string one[N] = { "for","name","for","you","your","my" };
	string two[N] = { "for","she","he","it","his","mine" };
	set<string> A(one, one + N);
	set<string> B(two, two + N);
	ostream_iterator<string, char> out(cout," ");
	cout << "set A:\n";
	copy(A.begin(), A.end(), out);
	cout << "\nset B:\n";
	copy(B.begin(), B.end(), out);
	cout << endl;

	cout << "union of A and B:\n";
	set_union(A.begin(), A.end(), B.begin(), B.end(), out);
	cout << endl;
	cout << "difference of A and B:\n";
	set_difference(A.begin(), A.end(), B.begin(), B.end(), out);
	cout << endl;
	cout << "intersection of A and B:\n";
	set_intersection(A.begin(), A.end(), B.begin(), B.end(), out);
	cout << endl;
	cout << "inster:\n";
	set<string> C;
	string s1("panny");
	C.insert(s1);
	copy(C.begin(), C.end(), out);
	cout << endl;
	cout << "showing a range:\n";
	copy(A.lower_bound("for"), A.upper_bound("name"), out);
	cout << endl;
	set<string> D;
	insert_iterator<set<string>> out1(D, D.begin());
	set_union(A.begin(), A.end(), B.begin(), B.end(), out1);
	cout << "set D:\n";
	copy(D.begin(), D.end(), out);
	cout << endl;

}
/*--------------------use multimap----------------------*/
void use_multimap()
{
	using namespace std;
	//count, lowwer_bound, upper_bound
	//pair<first,second>
	typedef int KeyType;
	typedef multimap<const KeyType, string> MapCode;
	typedef pair<KeyType, string> Pair;
	MapCode sample;
	Pair one(123, "Beijing");
	sample.insert(one);
	sample.insert(Pair(123, "Tokeu"));
	sample.insert(Pair(145, "Nanjing"));
	sample.insert(Pair(125, "Yinchuan"));
	multimap<const KeyType, string>::iterator pr;
	cout << "Number    Region\n";
	for (pr = sample.begin(); pr != sample.end(); pr++)
		cout << (*pr).first << "     " << (*pr).second << endl;
	cout << "number 123 region:\n";
	cout<<sample.count(123);
	cout << endl;
	cout << "output region with equal number:\n ";
	pair<MapCode::iterator, MapCode::iterator> range = sample.equal_range(123);
	for (pr = range.first; pr != range.second; pr++)
		cout << (*pr).second<<endl;
	cout << endl;
}
/*---------------use functor------------------*/
void outint(const int n) { std::cout << n << " "; }

template<class T>
class Toobig {
private:
	T cutoff;
public:
	Toobig(const T & v) :cutoff(v) {}
	bool operator()(const T &v) { return v > cutoff; }

};

void use_functor()
{

	using namespace std;
	//use list : remove_if()
	list<int> one = { 120,456,784,12,74,56,23,15,18,56,102};
	list<int>::iterator pr;
	/*--first way to output--*/
	ostream_iterator<int, char> out (std::cout, " ");
	copy(one.begin(), one.end(), out);
	cout << endl;
	/*--second way to output--*/
	for (pr = one.begin(); pr != one.end(); pr++)
		cout << *pr<<" ";
	cout << endl;
	/*--third way to output*/
	for_each(one.begin(), one.end(), outint);
	cout << endl << endl;
	Toobig<int> big(100);
	one.remove_if(big);
	for_each(one.begin(), one.end(), outint);


}
int main()
{
	std::cout << "----------------use list-------------------\n\n";
	use_list();
	std::cout << "------------------use set---------------------\n\n";
	use_set();
	std::cout << "--------------------use multimap------------------\n\n";
	use_multimap();
	std::cout << "----------------------use functor--------------------\n\n";
	use_functor();
	std::cout << std::endl;
	system("pause");
}