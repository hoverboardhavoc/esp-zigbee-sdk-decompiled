/*
 * Last changed at upstream commit d7e241034cb0adc2116988a320badb285c391de3
 * https://github.com/espressif/esp-zigbee-sdk/commit/d7e241034cb0adc2116988a320badb285c391de3
 * Upstream date: 2024-02-06 17:30:29 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.1.1(0cd72dc5)
 * Source: libesp_zb_cli_command -> zb_esp_cli_cmd_bdb.o -> cmd_zb_factory_reset
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Control flow encountered bad instruction data */

void cmd_zb_factory_reset(char *param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  if (param_1 == (char *)0x0) {
    uVar2 = esp_log_timestamp();
    esp_log_write(1,0x10000,&_LC8,uVar2,0x10000,"cmd_zb_factory_reset",0x36c);
  }
  else {
    iVar1 = strcmp(param_1,"help");
    if (iVar1 == 0) {
      uVar2 = esp_log_timestamp();
      esp_log_write(3,0x10000,&_L0,uVar2,0x10000);
      done_or_failed(0);
    }
    else {
      iVar1 = strcmp(param_1,"get");
      if (iVar1 == 0) {
        uVar2 = esp_log_timestamp();
        esp_log_write(3,0x10000,&_LC84,uVar2,0x10000);
        uVar2 = 0;
      }
      else {
        iVar1 = strcmp(param_1,"0");
        if (iVar1 == 0) {
          uVar2 = esp_log_timestamp();
          esp_log_write(3,0x10000,&_LC86,uVar2,0x10000);
          zb_bdb_reset_via_local_action(0);
          uVar2 = 0;
        }
        else {
          iVar1 = strcmp(param_1,"1");
          if (iVar1 == 0) {
            uVar2 = esp_log_timestamp();
            esp_log_write(3,0x10000,&_LC88,uVar2,0x10000);
            esp_restart();
_L0:
            uVar2 = esp_log_timestamp();
            esp_log_write(3,0x10000,&_LC90,uVar2,0x10000);
            zb_nvram_erase();
            DAT_0001b65d = DAT_0001b65d | 8;
            esp_restart();
                    /* WARNING: Bad instruction - Truncating control flow here */
            halt_baddata();
          }
          iVar1 = strcmp(param_1,"2");
          if (iVar1 == 0) goto _L0;
          uVar2 = esp_log_timestamp();
          esp_log_write(1,0x10000,&_LC91,uVar2,0x10000);
          uVar2 = 0xffffffff;
        }
      }
      done_or_failed(uVar2);
    }
  }
  return;
}

