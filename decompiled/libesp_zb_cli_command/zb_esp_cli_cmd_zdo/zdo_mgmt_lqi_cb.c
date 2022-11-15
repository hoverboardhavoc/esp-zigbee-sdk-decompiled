/*
 * Last changed at upstream commit 55d58f0243c7dca5c0887a2b065178dacc2d00be
 * https://github.com/espressif/esp-zigbee-sdk/commit/55d58f0243c7dca5c0887a2b065178dacc2d00be
 * Upstream date: 2022-11-15 14:25:21 +0800
 * Upstream subject: cli: Add cli example
 * Source: libesp_zb_cli_command -> zb_esp_cli_cmd_zdo.o -> zdo_mgmt_lqi_cb
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 zdo_mgmt_lqi_cb(int param_1,undefined4 param_2)

{
  byte bVar1;
  byte bVar2;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  char *pcVar6;
  uint uVar7;
  char acStack_58 [20];
  char acStack_44 [32];
  
  iVar4 = zb_buf_begin_func(param_2);
  if (*(char *)(iVar4 + 1) == '\0') {
    if (*(char *)(iVar4 + 3) == *(char *)(param_1 + 8)) {
      uVar5 = esp_log_timestamp();
      esp_log_write(3,&_LC3,&_L0,uVar5,&_LC3);
    }
    uVar7 = 0;
    while( true ) {
      bVar2 = *(byte *)(iVar4 + 4);
      uVar3 = (uint)bVar2;
      if (uVar3 <= uVar7) break;
      uVar3 = 0;
      for (bVar2 = 0; bVar2 < 8; bVar2 = bVar2 + 1) {
        sprintf(acStack_58 + uVar3,"%02x");
        uVar3 = uVar3 + 2 & 0xff;
      }
      acStack_58[uVar3] = '\0';
      uVar3 = 0;
      for (bVar2 = 0; bVar2 < 8; bVar2 = bVar2 + 1) {
        sprintf(acStack_44 + uVar3,"%02x");
        uVar3 = uVar3 + 2 & 0xff;
      }
      acStack_44[uVar3] = '\0';
      uVar5 = esp_log_timestamp();
      esp_log_write(3,&_LC3,&_LC49,uVar5,&_LC3,*(byte *)(iVar4 + 3) + uVar7,acStack_58,acStack_44);
      uVar7 = uVar7 + 1 & 0xff;
    }
    bVar1 = *(byte *)(iVar4 + 3);
    uVar7 = uVar3 + bVar1;
    if (uVar7 < *(byte *)(iVar4 + 2)) {
      if (uVar7 < 0xff) {
        if (uVar3 == 0) {
          uVar5 = 1;
        }
        else {
          zb_buf_reuse_func(param_2);
          pcVar6 = (char *)zb_buf_get_tail_func(param_2,4);
          *pcVar6 = bVar2 + bVar1;
          *(undefined2 *)(pcVar6 + 2) = *(undefined2 *)(param_1 + 10);
          iVar4 = zb_zdo_mgmt_lqi_req(param_2,zdo_request_cb);
          *(char *)(param_1 + 4) = (char)iVar4;
          if (iVar4 == 0xff) {
            uVar5 = 1;
          }
          else {
            uVar5 = 0;
          }
        }
      }
      else {
        uVar5 = 1;
      }
    }
    else {
      uVar5 = 1;
    }
  }
  else {
    uVar5 = 1;
  }
  return uVar5;
}

