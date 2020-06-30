
int gboot_main()
{ 	
     int num;
     //unsigned char buf[1024];
     #ifdef MMU_ON  //如果定义了MMU_ON
     mmu_init();
     #endif

     led_init();
       
     button_init();
     
     irq_init();
     
     uart_init();
     
      
   // dma_init();
    
  //  dma_start();
     
     send_data(0x10);
     send_data('\n');
     send_data('Y');
      
    /*NF_Erase(32*2+1);  
     buf[0] = 100;
     NF_WritePage(32*2+1, buf);
      buf[0] = 50;
      NF_PageRead(32*2+1, buf);
      if( buf[0] ==100)
      led_on();
     */ //检测nandflash的读写
        
     while(1)
     {
       	printf("\n***************************************\n\r");
    	printf("\n*****************GBOOT*****************\n\r");
    	printf("1:Download Linux Kernel from TFTP Server!\n\r");
    	printf("2:Boot Linux from RAM!\n\r");
    	printf("3:Boor Linux from Nand Flash!\n\r");  //换行，并回到行首
    	printf("\nPlese Select:");
    	
    	scanf("%d", &num);
    	
    	switch (num)
    	{
         case 1:
         //tftp_load();
         break;
         
         case 2:
         //boot_linux_ram();
         break;
         
         case 3:
         //boot_linux_nand();
         break;	
         
         default:
         printf("Error: wrong selection!\n\r");
         break;	
    	}
     }
     
     return 0;        
}
