#include "p0_starter.h" 
#include <vector>

int main()
{
	scudb::RowMatrix<int> A(2,3);
	std::vector<int> a(6,2);
	//验证FillFrom()函数
	A.FillFrom(a);
	std::cout << "矩阵A：" << std::endl;
	scudb::RowMatrixOperations<int>::Show(A);
	//验证GetRowCount()和GetColumnCount() 
	std::cout << "A的行数：" << A.GetRowCount() << " " << "列数：" << A.GetColumnCount() << std::endl;
	//验证GetElement()
	std::cout << "A的第(1,1)个元素值为：" << A.GetElement(1, 1) << std::endl;
	//验证SetElement()
	A.SetElement(1, 1, 1);
	std::cout << "将该位置元素值变为1后的A：" << std::endl;
	scudb::RowMatrixOperations<int>::Show(A);
	//验证Add()
	std::unique_ptr<scudb::RowMatrix<int>> sum = scudb::RowMatrixOperations<int>::Add(&A, &A);
	std::cout << "A+A结果为：" << std::endl;
	scudb::RowMatrixOperations<int>::Show(*sum);
	scudb::RowMatrix<int> B(3, 2);
	std::vector<int> b(6, 3);
	B.FillFrom(b);
	std::cout << "矩阵B：" << std::endl;
	scudb::RowMatrixOperations<int>::Show(B);
	//验证Multiply()
	std::unique_ptr<scudb::RowMatrix<int>> product = scudb::RowMatrixOperations<int>::Multiply(&A, &B);
	std::cout << "A*B结果为：" << std::endl;
	scudb::RowMatrixOperations<int>::Show(*product);
	scudb::RowMatrix<int> C(2, 2);
	std::vector<int> c(4, 1);
	C.FillFrom(c);
	std::cout << "矩阵C：" << std::endl;
	scudb::RowMatrixOperations<int>::Show(C);
	//验证GEMM()
	std::unique_ptr<scudb::RowMatrix<int>> gemm = scudb::RowMatrixOperations<int>::GEMM(&A, &B, &C);
	std::cout << "A*B+C结果为：" << std::endl;
	scudb::RowMatrixOperations<int>::Show(*gemm);
}
