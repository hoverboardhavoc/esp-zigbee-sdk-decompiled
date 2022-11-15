/*
 * Last changed at upstream commit 55d58f0243c7dca5c0887a2b065178dacc2d00be
 * https://github.com/espressif/esp-zigbee-sdk/commit/55d58f0243c7dca5c0887a2b065178dacc2d00be
 * Upstream date: 2022-11-15 14:25:21 +0800
 * Upstream subject: cli: Add cli example
 * Source: libesp_zb_cli_command -> zb_esp_cli_cmd_zdo.o -> cmd_zb_bind_unbind_cb
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void cmd_zb_bind_unbind_cb(undefined4 param_1)

{
  undefined1 *puVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  
  puVar1 = (undefined1 *)zb_buf_begin_func();
  iVar2 = get_ctx_by_tsn(*puVar1);
  if (iVar2 == 0) {
    zb_buf_free_func(param_1);
  }
  else {
    iVar3 = zb_schedule_alarm_cancel(cmd_zb_bind_unbind_timeout,0xff,0);
    if (iVar3 != 0) {
      uVar4 = esp_log_timestamp();
      esp_log_write(1,&_LC3,&_L0,uVar4,&_LC3);
    }
    if (puVar1[1] == '\0') {
      uVar4 = esp_log_timestamp();
      esp_log_write(3,&_LC3,&_LC7,uVar4,&_LC3);
    }
    else {
      uVar4 = esp_log_timestamp();
      esp_log_write(1,&_LC3,&_LC8,uVar4,&_LC3);
    }
    invalidate_ctx(iVar2);
    zb_buf_free_func(param_1);
  }
  return;
}

