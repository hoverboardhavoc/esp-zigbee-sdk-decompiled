/*
 * Last changed at upstream commit 2fe15bae2e4382ac99f249a0934066f5d5a5c684
 * https://github.com/espressif/esp-zigbee-sdk/commit/2fe15bae2e4382ac99f249a0934066f5d5a5c684
 * Upstream date: 2024-03-08 17:10:04 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.0(9d7e9ff2)
 * Source: libesp_zb_cli_command -> zb_esp_cli_cmd_bdb.o -> cmd_zb_nwk_state
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void cmd_zb_nwk_state(int param_1,undefined4 *param_2)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  char *pcVar5;
  
  if (param_1 == 0) {
    uVar3 = esp_log_timestamp();
    esp_log_write(1,0x10000,&_LC14,uVar3,0x10000,"cmd_zb_nwk_state",0x132);
  }
  else {
    iVar1 = strcmp((char *)*param_2,"help");
    if (iVar1 == 0) {
      uVar3 = esp_log_timestamp();
      esp_log_write(3,0x10000,&_LC53,uVar3,0x10000);
      done_or_failed(0);
    }
    else {
      iVar1 = zb_zdo_joined();
      if (iVar1 == 0) {
        iVar1 = strcmp((char *)*param_2,"get");
        if (iVar1 == 0) {
          uVar3 = esp_log_timestamp();
          esp_log_write(3,0x10000,&_LC33,uVar3,0x10000);
          uVar3 = 0;
        }
        else {
          uVar3 = esp_log_timestamp();
          esp_log_write(1,0x10000,&_LC25,uVar3,0x10000);
          uVar3 = 0xffffffff;
        }
      }
      else {
        pcVar5 = (char *)*param_2;
        iVar1 = strcmp(pcVar5,"get");
        if (iVar1 == 0) {
          uVar3 = esp_log_timestamp();
          if (DAT_000190f4 == '\0') {
            pcVar5 = "Close";
          }
          else {
            pcVar5 = "network is closed";
          }
          esp_log_write(3,0x10000,&_LC54,uVar3,0x10000,pcVar5);
          uVar3 = 0;
        }
        else {
          iVar1 = strcmp(pcVar5,"close");
          if (iVar1 == 0) {
            uVar3 = zb_bdb_close_network();
            uVar4 = esp_log_timestamp();
            esp_log_write(3,0x10000,&_LC56,uVar4,0x10000);
          }
          else {
            iVar1 = strcmp(pcVar5,"open");
            if (iVar1 == 0) {
              if ((char *)param_2[1] == (char *)0x0) {
                uVar2 = 0xb4;
              }
              else {
                uVar2 = atoi((char *)param_2[1]);
                uVar2 = uVar2 & 0xff;
              }
              uVar3 = zb_bdb_open_network(uVar2);
              uVar4 = esp_log_timestamp();
              esp_log_write(3,0x10000,&_LC58,uVar4,0x10000,uVar2);
            }
            else {
              uVar3 = esp_log_timestamp();
              esp_log_write(1,0x10000,&_LC25,uVar3,0x10000);
              uVar3 = 0;
            }
          }
        }
      }
      done_or_failed(uVar3);
    }
  }
  return;
}

