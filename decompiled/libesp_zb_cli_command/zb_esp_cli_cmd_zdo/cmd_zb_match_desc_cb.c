/*
 * Last changed at upstream commit 790bc8d6ece1bf5f739debaa4aa4af508982070a
 * https://github.com/espressif/esp-zigbee-sdk/commit/790bc8d6ece1bf5f739debaa4aa4af508982070a
 * Upstream date: 2023-12-21 19:52:25 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.0.7(bdde218a)
 * Source: libesp_zb_cli_command -> zb_esp_cli_cmd_zdo.o -> cmd_zb_match_desc_cb
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void cmd_zb_match_desc_cb(undefined4 param_1)

{
  undefined1 *puVar1;
  undefined1 *puVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  
  puVar2 = (undefined1 *)zb_buf_begin_func();
  iVar3 = zb_buf_get_tail_func(param_1,0x1c);
  iVar4 = get_ctx_by_tsn(*puVar2);
  if (iVar4 != 0) {
    if (puVar2[1] == '\0') {
      puVar1 = puVar2 + 5;
      while (puVar2[4] != '\0') {
        uVar5 = esp_log_timestamp();
        esp_log_write(3,&_LC0,&_LC16,uVar5,&_LC0,*(undefined2 *)(iVar3 + 1),*puVar1);
        puVar1 = puVar1 + 1;
        puVar2[4] = puVar2[4] + -1;
      }
      if (*(char *)(iVar4 + 6) == '\0') {
        uVar5 = esp_log_timestamp();
        esp_log_write(3,&_LC0,&_LC4,uVar5,&_LC0);
        invalidate_ctx(iVar4);
      }
    }
    else if (puVar2[1] == -0x7b) {
      uVar5 = esp_log_timestamp();
      esp_log_write(3,&_LC0,&_LC4,uVar5,&_LC0);
      invalidate_ctx(iVar4);
    }
  }
  zb_buf_free_func(param_1);
  return;
}

