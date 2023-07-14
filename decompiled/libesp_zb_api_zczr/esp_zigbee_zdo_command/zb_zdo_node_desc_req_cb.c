/*
 * Last changed at upstream commit 0de2da5bd0b050dcc5b1f7f4c5eba0b5eeccfd85
 * https://github.com/espressif/esp-zigbee-sdk/commit/0de2da5bd0b050dcc5b1f7f4c5eba0b5eeccfd85
 * Upstream date: 2023-07-14 11:30:10 +0800
 * Upstream subject: esp-zigbee-sdk: release v0.7.1(5785a2c)
 * Source: libesp_zb_api_zczr -> esp_zigbee_zdo_command.o -> zb_zdo_node_desc_req_cb
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zb_zdo_node_desc_req_cb(int param_1)

{
  undefined1 uVar1;
  undefined2 uVar2;
  void *__dest;
  undefined1 *puVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  
  uVar2 = ZDO_INVALID_SHORT_ADDR;
  __dest = malloc(0xd);
  puVar3 = (undefined1 *)zb_buf_begin_func(param_1);
  uVar1 = *puVar3;
  iVar4 = zb_buf_begin_func(param_1);
  if (*(char *)(iVar4 + 1) == '\0') {
    uVar2 = *(undefined2 *)(iVar4 + 2);
    memcpy(__dest,(void *)(iVar4 + 4),0xd);
    iVar5 = zb_schedule_alarm_cancel(node_desc_req_timeout,0xff,0);
    if (iVar5 != 0) {
      uVar6 = esp_log_timestamp();
      esp_log_write(1,0x10000,&_LC17,uVar6,0x10000,"zb_zdo_node_desc_req_cb",0x18b);
      return;
    }
  }
  iVar5 = esp_zb_zdo_callback_find(uVar1);
  if (((iVar5 != 0) && (*(char *)(iVar5 + 1) == '\x02')) && (*(code **)(iVar5 + 4) != (code *)0x0))
  {
    (**(code **)(iVar5 + 4))(*(undefined1 *)(iVar4 + 1),uVar2,__dest,*(undefined4 *)(iVar5 + 8));
  }
  esp_zb_zdo_callback_remove(uVar1);
  if (param_1 != 0) {
    zb_buf_free_func(param_1);
  }
  free(__dest);
  return;
}

