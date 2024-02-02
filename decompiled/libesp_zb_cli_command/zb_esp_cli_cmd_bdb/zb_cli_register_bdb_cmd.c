/*
 * Last changed at upstream commit 2e2b779251f791b76c34cc582bf68595de9ac19b
 * https://github.com/espressif/esp-zigbee-sdk/commit/2e2b779251f791b76c34cc582bf68595de9ac19b
 * Upstream date: 2024-02-02 22:15:44 +0800
 * Upstream subject: feat(spinel): support zigbee radio spinel
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
  undefined *puStack_2c;
  char *pcStack_28;
  undefined4 uStack_24;
  code *pcStack_20;
  undefined4 *puStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  
  bdb_args = arg_str0(&_LC51,&_LC50,"<role>",
                      "Set or get the Zigbee role of a device. [Setting only before bdb start. Reading only after bdb start.]"
                     );
  DAT_000121a8 = arg_str0(&_LC55,"extpanid","<extpanid>",
                          "Set or get the Zigbee Extended Pan ID value. [Setting only before bdb start. Reading only after bdb start.]"
                         );
  DAT_000121ac = arg_str0(&_LC59,"panid","<panid>",
                          "Set or get the Zigbee PAN ID value. [Setting only before bdb start. Reading only after bdb start.]"
                         );
  DAT_000121b0 = arg_lit0(&_LC62,"start","Start the commissioning process");
  DAT_000121b4 = arg_str0(&_LC66,"channel","<channel>","Set or get 802.15.4 channel");
  DAT_000121b8 = arg_str0(&_LC70,&_LC69,"<ic_operation>",
                          "Set install code on the device, add information about the install code on the trust center, set the trust center install code policy."
                         );
  DAT_000121bc = arg_strn(0,0,&_LC72,0,1,"Set install code on the device.");
  DAT_000121c0 = arg_strn(0,0,&_LC72,0,1,"Set eui64 of the device install code on.");
  DAT_000121c4 = arg_str0(&_LC77,"legacy","<enable/disable>",
                          "Enable or disable the legacy device support");
  DAT_000121c8 = arg_str0(&_LC81,"nwkkey","<key>","Set network key");
  DAT_000121cc = arg_lit0(&_LC84,"factory_reset","factory reset");
  DAT_000121d0 = arg_str0(&_LC88,"childmax","<max_children>","Set max children");
  DAT_000121d4 = arg_end(0xd);
  uStack_24 = 0;
  uStack_18 = 0;
  uStack_14 = 0;
  puStack_2c = &_LC89;
  pcStack_28 = "ZigBee bdb command";
  pcStack_20 = zb_cli_bdb_cmd_cb;
  puStack_1c = &bdb_args;
  iVar1 = esp_console_cmd_register(&puStack_2c);
  if (iVar1 == 0) {
    return;
  }
  _esp_error_check_failed
            ("/home/xusiyu/esp/esp-zboss/components/zboss_cli_command/zb_esp_cli_cmd_bdb.c",0x29c,
             "zb_cli_register_bdb_cmd","esp_console_cmd_register(&bdb_cmd)");
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

