/*
 * Last changed at upstream commit 790bc8d6ece1bf5f739debaa4aa4af508982070a
 * https://github.com/espressif/esp-zigbee-sdk/commit/790bc8d6ece1bf5f739debaa4aa4af508982070a
 * Upstream date: 2023-12-21 19:52:25 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.0.7(bdde218a)
 * Source: libesp_zb_cli_command -> zb_esp_cli_cmd_zdo.o -> cmd_zb_ieee_addr_cb
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void cmd_zb_ieee_addr_cb(undefined4 param_1)

{
  undefined1 *puVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined1 uStack_1b;
  undefined2 uStack_1a;
  undefined1 auStack_18 [5];
  undefined1 uStack_13;
  undefined1 uStack_12;
  undefined1 uStack_11;
  
  puVar1 = (undefined1 *)zb_buf_begin_func();
  iVar2 = get_ctx_by_tsn(*puVar1);
  if (iVar2 == 0) {
    zb_buf_free_func(param_1);
  }
  else {
    iVar3 = zb_schedule_alarm_cancel(cmd_zb_ieee_addr_timeout,0xff,0);
    if (iVar3 != 0) {
      uVar4 = esp_log_timestamp();
      esp_log_write(1,&_LC0,&_L0,uVar4,&_LC0);
    }
    if (puVar1[1] == '\0') {
      zb_memcpy8(auStack_18,puVar1 + 2);
      uStack_1a = *(undefined2 *)(puVar1 + 10);
      iVar3 = zb_address_update(auStack_18,uStack_1a,1,&uStack_1b);
      if (iVar3 == 0) {
        uVar4 = esp_log_timestamp();
        esp_log_write(3,&_LC0,&_L0,uVar4,&_LC0,uStack_11,uStack_12,uStack_13);
        uVar4 = esp_log_timestamp();
        esp_log_write(3,&_LC0,&_LC4,uVar4,&_LC0);
      }
      else {
        uVar4 = esp_log_timestamp();
        esp_log_write(1,&_LC0,&_LC14,uVar4,&_LC0);
      }
    }
    else {
      uVar4 = esp_log_timestamp();
      esp_log_write(1,&_LC0,&_LC15,uVar4,&_LC0);
    }
    invalidate_ctx(iVar2);
    zb_buf_free_func(param_1);
  }
  return;
}

