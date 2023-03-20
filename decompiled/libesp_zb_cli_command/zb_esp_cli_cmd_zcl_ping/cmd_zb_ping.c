/*
 * Last changed at upstream commit 8f416d47159477fb2dfe72f817700bc25debb587
 * https://github.com/espressif/esp-zigbee-sdk/commit/8f416d47159477fb2dfe72f817700bc25debb587
 * Upstream date: 2023-03-20 14:23:27 +0800
 * Upstream subject: zcl: support more ZCL cluster(caef391)
 * Source: libesp_zb_cli_command -> zb_esp_cli_cmd_zcl_ping.o -> cmd_zb_ping
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void cmd_zb_ping(int param_1,undefined4 *param_2)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  
  if (param_1 == 2) {
    iVar3 = zb_ping_acquire_request();
    if (iVar3 == 0) {
      uVar2 = esp_log_timestamp();
      esp_log_write(1,&_LC0,&_LC18,uVar2,&_LC0);
    }
    else {
      *(code **)(iVar3 + 0x18) = ping_cli_evt_handler;
      *(undefined2 *)(iVar3 + 0xe) = 10000;
      cVar1 = parse_address(*param_2,iVar3 + 1,1);
      *(char *)(iVar3 + 9) = cVar1;
      if (cVar1 == '\0') {
        uVar2 = esp_log_timestamp();
        esp_log_write(1,&_LC0,&_LC19,uVar2,&_LC0);
        zb_ping_release_request(iVar3);
      }
      else {
        iVar4 = sscanf((char *)param_2[1],"%hd");
        if (iVar4 == 0) {
          uVar2 = esp_log_timestamp();
          esp_log_write(1,&_LC0,&_LC21,uVar2,&_LC0);
          zb_ping_release_request(iVar3);
        }
        else {
          if (0x4f < *(ushort *)(iVar3 + 0xc)) {
            uVar2 = esp_log_timestamp();
            esp_log_write(1,&_LC0,&_LC22,uVar2,&_LC0);
            *(undefined2 *)(iVar3 + 0xc) = 0x4f;
          }
          ping_request_send(iVar3);
        }
      }
    }
  }
  else {
    uVar2 = esp_log_timestamp();
    esp_log_write(1,&_LC0,&_L0,uVar2,&_LC0);
  }
  return;
}

