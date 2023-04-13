library IEEE;
use IEEE.STD_logic_1164.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;    -- καλουμε τις καταλληλες βιβλιοθηκες 
use ieee.NUMERIC_STD.all;


entity askisi3 is   -- οντοτητα 
generic(
		constant N:natural:= 1
		);
		
		Port(
		A, B     : in  STD_LOGIC_VECTOR(7 downto 0);			-- εδω φτιαχνουμε τις εισοδους οι οποιοι θα εναι των 8 bit 
		ALU_Sel  : in  STD_LOGIC_VECTOR(3 downto 0);			-- η εισοδος για την επιλογη της πραξης 
		ALU_Out   : out  STD_LOGIC_VECTOR(7 downto 0); -- 1 output 8-bit
		Carryout : out std_logic
		);
end askisi3;
	
architecture askisi3 of askisi3 is   -- αρχιτεκτινικη και δηλωση σηματων για την μεταβλητη της εξοδου 


signal ALU_Result : std_logic_vector (7 downto 0); 
signal tmp: std_logic_vector (8 downto 0);


begin 
process (A,B,ALU_Sel)
begin
	case(ALU_SEl)is     -- εδω ξεκιναει ο κωδικας και με την βοηθεια των ελεγχων μεσω case κανουμε την καθε πραξη 
	when "0000"=>
		ALU_Result <= A + B ; 
	when "0001" => -- Subtraction
   ALU_Result <= A - B ;
  when "0010" => -- Multiplication
   ALU_Result <= std_logic_vector(to_unsigned((to_integer(unsigned(A)) * to_integer(unsigned(B))),8)) ;
  when "0011" => -- Division
   ALU_Result <= std_logic_vector(to_unsigned(to_integer(unsigned(A)) / to_integer(unsigned(B)),8)) ;
  when "0100" => -- Logical shift left
   ALU_Result <= std_logic_vector(unsigned(A) sll N);
  when "0101" => -- Logical shift right
   ALU_Result <= std_logic_vector(unsigned(A) srl N);
  when "0110" => --  Rotate left
   ALU_Result <= std_logic_vector(unsigned(A) rol N);
  when "0111" => -- Rotate right
   ALU_Result <= std_logic_vector(unsigned(A) ror N);
  when "1000" => -- Logical and 
   ALU_Result <= A and B;
  when "1001" => -- Logical or
   ALU_Result <= A or B;
  when "1010" => -- Logical xor 
   ALU_Result <= A xor B;
  when "1011" => -- Logical nor
   ALU_Result <= A nor B;
  when "1100" => -- Logical nand 
   ALU_Result <= A nand B;
  when "1101" => -- Logical xnor
   ALU_Result <= A xnor B;
  when "1110" => -- συγκριση 
   if(A>B) then
    ALU_Result <= x"01" ;
   else
    ALU_Result <= x"00" ;
   end if; 
  when "1111" => --ισοτητα 
   if(A=B) then
    ALU_Result <= x"01" ;
   else
    ALU_Result <= x"00" ;
   end if;
  when others => ALU_Result <= A + B ; 
  end case;
 end process;
	
	ALU_Out <= ALU_Result; -- ALU out
 tmp <= ('0' & A) + ('0' & B);
 Carryout <= tmp(8); -- Carryout flag
	end askisi3;
	