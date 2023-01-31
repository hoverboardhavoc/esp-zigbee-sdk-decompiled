/*
 * Last changed at upstream commit 2defb30a96c2ca2505573e1ca35f3ee56a3c9daf
 * https://github.com/espressif/esp-zigbee-sdk/commit/2defb30a96c2ca2505573e1ca35f3ee56a3c9daf
 * Upstream date: 2023-01-31 10:56:39 +0800
 * Upstream subject: example: Support new zdo API(0d9da4e)
 * Source: libesp_zb_cli_command -> zb_esp_cli_cmd_bdb.o -> zb_cli_register_bdb_cmd
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Control flow encountered bad instruction data */

void zb_cli_register_bdb_cmd(void)

{
  int iVar1;
  undefined *puStack_24;
  char *pcStack_20;
  undefined4 uStack_1c;
  code *pcStack_18;
  undefined4 *puStack_14;
  
  bdb_args = arg_str0(&_LC54,&_LC53,"<role>",
                      "Set or get the Zigbee role of a device. [Setting only before bdb start. Reading only after bdb start.]"
                     );
  DAT_0001215c = arg_str0(&_LC58,"extpanid","<extpanid>",
                          "Set or get the Zigbee Extended Pan ID value. [Setting only before bdb start. Reading only after bdb start.]"
                         );
  DAT_00012160 = arg_str0(&_LC62,"panid","<panid>",
                          "Set or get the Zigbee PAN ID value. [Setting only before bdb start. Reading only after bdb start.]"
                         );
  DAT_00012164 = arg_lit0(&_LC65,"start","Start the commissioning process");
  DAT_00012168 = arg_str0(&_LC69,"channel","<channel>","Set or get 802.15.4 channel");
  DAT_0001216c = arg_str0(&_LC73,&_LC72,"<ic_operation>",
                          "Set install code on the device, add information about the install code on the trust center, set the trust center install code policy."
                         );
  DAT_00012170 = arg_strn(0,0,&_LC75,0,1,"Set install code on the device.");
  DAT_00012174 = arg_strn(0,0,&_LC75,0,1,"Set eui64 of the device install code on.");
  DAT_00012178 = arg_str0(&_LC80,"legacy","<enable/disable>",
                          "Enable or disable the legacy device support");
  DAT_0001217c = arg_str0(&_LC84,"nwkkey","<key>","Set network key");
  DAT_00012180 = arg_lit0(&_LC87,"factory_reset","factory reset");
  DAT_00012184 = arg_str0(&_LC91,"childmax","<max_children>","Set max children");
  DAT_00012188 = arg_end(0xd);
  puStack_24 = &_LC0;
  pcStack_20 = "ZigBee bdb command";
  uStack_1c = 0;
  pcStack_18 = zb_cli_bdb_cmd_cb;
  puStack_14 = &bdb_args;
  iVar1 = esp_console_cmd_register(&puStack_24);
  if (iVar1 == 0) {
    return;
  }
  _esp_error_check_failed
            ("/home/likunqiao/esp/esp-zboss/components/zboss_cli_command/zb_esp_cli_cmd_bdb.c",0x29c
             ,"zb_cli_register_bdb_cmd","esp_console_cmd_register(&bdb_cmd)");
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

