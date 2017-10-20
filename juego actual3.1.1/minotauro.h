
class Minotauro {

	private:
		int x,y,vida;
		bool skill,skill2,skill3;
		bool CD1,CD2,CD3;
		void mover;
		void hab1;
		void hab2;
		void hab3;
		void morir;
		void spawn;
	public:
		Minotauro() {}
		virtual ~Minotauro() {}
		Minotauro(const Minotauro& other) {}
		int Getx,y,vida() { return x,y,vida; }
		void Setx,y,vida(int val) { x,y,vida = val; }
		bool Getskill,skill2,skill3() { return skill,skill2,skill3; }
		void Setskill,skill2,skill3(bool val) { skill,skill2,skill3 = val; }
		bool GetCD1,CD2,CD3() { return CD1,CD2,CD3; }
		void SetCD1,CD2,CD3(bool val) { CD1,CD2,CD3 = val; }
		void Getmover() { return mover; }
		void Setmover(void val) { mover = val; }
		void Gethab1() { return hab1; }
		void Sethab1(void val) { hab1 = val; }
		void Gethab2() { return hab2; }
		void Sethab2(void val) { hab2 = val; }
		void Gethab3() { return hab3; }
		void Sethab3(void val) { hab3 = val; }
		void Getmorir() { return morir; }
		void Setmorir(void val) { morir = val; }
		void Getspawn() { return spawn; }
		void Setspawn(void val) { spawn = val; }
	protected:

};
