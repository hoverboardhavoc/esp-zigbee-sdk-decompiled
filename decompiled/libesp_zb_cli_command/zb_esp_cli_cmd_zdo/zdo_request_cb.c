/*
 * Last changed at upstream commit d7e241034cb0adc2116988a320badb285c391de3
 * https://github.com/espressif/esp-zigbee-sdk/commit/d7e241034cb0adc2116988a320badb285c391de3
 * Upstream date: 2024-02-06 17:30:29 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.1.1(0cd72dc5)
 * Source: libesp_zb_cli_command -> zb_esp_cli_cmd_zdo.o -> zdo_request_cb
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zdo_request_cb(undefined4 param_1)

{
  undefined1 uVar1;
  undefined1 *puVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  
  puVar2 = (undefined1 *)zb_buf_begin_func();
  uVar1 = *puVar2;
  puVar3 = (undefined4 *)get_ctx_by_tsn(uVar1);
  if (puVar3 == (undefined4 *)0x0) {
    uVar5 = esp_log_timestamp();
    esp_log_write(1,&_LC0,&_L0,uVar5,&_LC0,*puVar2);
    zb_buf_free_func(param_1);
    return;
  }
  iVar4 = zb_schedule_alarm_cancel(ctx_timeout_cb,uVar1,0);
  if (iVar4 == 0) {
    if ((code *)*puVar3 == (code *)0x0) goto _L0;
    iVar4 = (*(code *)*puVar3)(puVar3,param_1);
    if (iVar4 != 0) goto _L0;
    iVar6 = zb_schedule_app_alarm(ctx_timeout_cb,*(undefined1 *)(puVar3 + 1),0x14a);
    if (iVar6 != 0) {
      uVar5 = esp_log_timestamp();
      esp_log_write(1,&_LC0,&_LC57,uVar5,&_LC0);
      goto _L0;
    }
  }
  else {
    zb_assert("/home/xiaqilin/esp/esp-zboss/components/zboss_cli_command/zb_esp_cli_cmd_zdo.c",0x5ec
             );
_L0:
    iVar4 = 1;
_L0:
    if (puVar2[1] == '\0') {
      uVar5 = esp_log_timestamp();
      esp_log_write(3,&_LC0,&_LC55,uVar5,&_LC0);
      uVar5 = esp_log_timestamp();
      esp_log_write(3,&_LC0,&_LC4,uVar5,&_LC0);
    }
    else {
      uVar5 = esp_log_timestamp();
      esp_log_write(1,&_LC0,&_LC56,uVar5,&_LC0,*puVar2,puVar2[1]);
    }
  }
  if (iVar4 == 0) {
    return;
  }
_L0:
  invalidate_ctx(puVar3);
  zb_buf_free_func(param_1);
  return;
}

