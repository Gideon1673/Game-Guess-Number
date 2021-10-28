# Hello-World
Hello, I'm going to learn C++ programming language.
  
VERSION 1.0
Game guessTheNumber bị lỗi ở một chỗ, khi số số hạng n mà log2(n) ra một số nguyên thì sẽ bị thiếu một lần đoán để 100% chiến thắng.  
Ví dụ: [1;8] thì game sẽ tính ra số lần đoán tối đa là 3, nhưng thực tế phải cần 4 lần đoán thì mới 100% chiến thắng 
! Đã sửa xong lỗi này
  
UPDATE VERSION 2.0
- Có 2 tính năng: Người đoán số do máy chọn và Máy đoán số do người chọn. Cả hai tính năng đều sẽ giới hạn lượt đoán nhưng sẽ 100% thắng nếu chơi theo binary search
- Bổ sung Cheat code trong chế độ người đoán số của máy: Nhập "-123456789" để hiện luôn đáp án
  
NHỮNG ĐIỀU CHƯA HOÀN THIỆN
- Code còn dài, lằng nhằng, rắc rối. Sợ sau này đọc lại sẽ không hiểu. Vì hồi đó suy nghĩ mãi không biết code như nào để ra được chế độ "Máy đoán số do người chọn" nên mới chỉ code được tính năng, còn refactoring code cho gọn gàng dễ hiểu thì chưa làm được.
