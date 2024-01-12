/*
 * Last changed at upstream commit 9e7fde9a71fb6810604eb3f5a1a644975d98cdc9
 * https://github.com/espressif/esp-zigbee-sdk/commit/9e7fde9a71fb6810604eb3f5a1a644975d98cdc9
 * Upstream date: 2024-01-12 14:14:49 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.0.8(0e41638c)
 * Source: libesp_zb_cli_command -> zb_esp_cli_cmd_zdo.o -> cmd_zb_active_ep_cb
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void cmd_zb_active_ep_cb(undefined4 param_1)

{
  byte bVar1;
  uint uVar2;
  undefined1 *puVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  char cStack_85;
  undefined4 auStack_84 [26];
  
  puVar3 = (undefined1 *)zb_buf_begin_func();
  zb_buf_begin_func(param_1);
  memset(auStack_84,0,100);
  iVar4 = get_ctx_by_tsn(*puVar3);
  if (iVar4 == 0) {
    zb_buf_free_func(param_1);
  }
  else {
    if (puVar3[1] == '\0') {
      uVar5 = esp_log_timestamp();
      esp_log_write(3,&_LC0,&_L0,uVar5,&_LC0,*(undefined2 *)(puVar3 + 2));
      auStack_84[0] = 0x3d7065;
      uVar2 = 3;
      for (bVar1 = 0; bVar1 < (byte)puVar3[4]; bVar1 = bVar1 + 1) {
        iVar6 = sprintf((char *)((int)auStack_84 + uVar2),"%d,");
        uVar2 = uVar2 + iVar6 & 0xff;
      }
      (&cStack_85)[uVar2] = '\0';
      uVar5 = esp_log_timestamp();
      esp_log_write(3,&_LC0,&_LC19,uVar5,&_LC0,auStack_84);
      uVar5 = esp_log_timestamp();
      esp_log_write(3,&_LC0,&_LC4,uVar5,&_LC0);
    }
    else {
      uVar5 = esp_log_timestamp();
      esp_log_write(1,&_LC0,&_LC20,uVar5,&_LC0);
    }
    invalidate_ctx(iVar4);
    zb_buf_free_func(param_1);
  }
  return;
}

