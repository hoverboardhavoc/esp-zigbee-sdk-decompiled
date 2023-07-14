/*
 * Last changed at upstream commit 0de2da5bd0b050dcc5b1f7f4c5eba0b5eeccfd85
 * https://github.com/espressif/esp-zigbee-sdk/commit/0de2da5bd0b050dcc5b1f7f4c5eba0b5eeccfd85
 * Upstream date: 2023-07-14 11:30:10 +0800
 * Upstream subject: esp-zigbee-sdk: release v0.7.1(5785a2c)
 * Source: libesp_zb_api_zczr -> esp_zigbee_zdo_command.o -> find_device_cb
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void find_device_cb(int param_1)

{
  undefined1 uVar1;
  int iVar2;
  int iVar3;
  undefined1 *puVar4;
  undefined4 uVar5;
  undefined2 uVar6;
  undefined1 uVar7;
  
  iVar2 = zb_buf_begin_func();
  iVar3 = zb_buf_get_tail_func(param_1,0x1c);
  uVar6 = ZDO_INVALID_SHORT_ADDR;
  uVar7 = ZDO_INVALID_ENDPOINT;
  puVar4 = (undefined1 *)zb_buf_begin_func(param_1);
  uVar1 = *puVar4;
  if ((*(char *)(iVar2 + 1) == '\0') && (*(char *)(iVar2 + 4) != '\0')) {
    uVar7 = *(undefined1 *)(iVar2 + 5);
    uVar6 = *(undefined2 *)(iVar3 + 1);
    iVar3 = zb_schedule_alarm_cancel(match_desc_req_device_timeout,0xff,0);
    if (iVar3 != 0) {
      uVar5 = esp_log_timestamp();
      esp_log_write(1,0x10000,&_LC3,uVar5,0x10000,"find_device_cb",0xeb);
      return;
    }
  }
  iVar3 = esp_zb_zdo_callback_find(uVar1);
  if (((iVar3 != 0) && (*(char *)(iVar3 + 1) == '\x06')) && (*(code **)(iVar3 + 4) != (code *)0x0))
  {
    (**(code **)(iVar3 + 4))(*(undefined1 *)(iVar2 + 1),uVar6,uVar7,*(undefined4 *)(iVar3 + 8));
  }
  esp_zb_zdo_callback_remove(uVar1);
  if (param_1 != 0) {
    zb_buf_free_func(param_1);
  }
  return;
}

