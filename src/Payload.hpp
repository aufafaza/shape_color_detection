class Payload { 
	private: 
		static bool Dropped; 
	public: 
		Payload();
		static bool Drop(bool detected); 
		static bool isDropped(); 
};

