/*
 * Last changed at upstream commit 8f416d47159477fb2dfe72f817700bc25debb587
 * https://github.com/espressif/esp-zigbee-sdk/commit/8f416d47159477fb2dfe72f817700bc25debb587
 * Upstream date: 2023-03-20 14:23:27 +0800
 * Upstream subject: zcl: support more ZCL cluster(caef391)
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
  undefined4 uStack_84;
  undefined1 auStack_80 [100];
  
  puVar3 = (undefined1 *)zb_buf_begin_func();
  zb_buf_begin_func(param_1);
  uStack_84 = 0;
  memset(auStack_80,0,0x60);
  iVar4 = get_ctx_by_tsn(*puVar3);
  if (iVar4 == 0) {
    zb_buf_free_func(param_1);
  }
  else {
    if (puVar3[1] == '\0') {
      uVar5 = esp_log_timestamp();
      esp_log_write(3,&_LC3,&_LC24,uVar5,&_LC3,*(undefined2 *)(puVar3 + 2));
      uStack_84 = 0x3d7065;
      uVar2 = 3;
      for (bVar1 = 0; bVar1 < (byte)puVar3[4]; bVar1 = bVar1 + 1) {
        iVar6 = sprintf(auStack_80 + (uVar2 - 4),"%d,");
        uVar2 = uVar2 + iVar6 & 0xff;
      }
      (&cStack_85)[uVar2] = '\0';
      uVar5 = esp_log_timestamp();
      esp_log_write(3,&_LC3,&_LC26,uVar5,&_LC3,&uStack_84);
      uVar5 = esp_log_timestamp();
      esp_log_write(3,&_LC3,&_LC7,uVar5,&_LC3);
    }
    else {
      uVar5 = esp_log_timestamp();
      esp_log_write(1,&_LC3,&_LC27,uVar5,&_LC3);
    }
    invalidate_ctx(iVar4);
    zb_buf_free_func(param_1);
  }
  return;
}

