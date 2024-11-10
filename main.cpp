#include <stdio.h>
#include<memory>

/// class
#include"Homebody.h"
#include"Jock.h"

int main() {
  
    /// 生成
    std::unique_ptr<HomeBody>homebody=std::make_unique<HomeBody>();
    std::unique_ptr<Jock> jock = std::make_unique<Jock>();

    /// 100メートル走をする処理
    printf("10kmマラソンをします\n\n");
    printf("引きこもり:");
    homebody->Run();
    printf("体育会系:");
    jock->Run();

    return 0;
}
