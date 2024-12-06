/*
 * Last changed at upstream commit 0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * https://github.com/espressif/esp-zigbee-sdk/commit/0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * Upstream date: 2024-12-06 13:11:49 +0800
 * Upstream subject: esp-zigbee-sdk: (e9475ff2)
 * Source: libesp_zb_api.zczr.debug -> esp_zigbee_zdo_command.o -> zb_zdo_node_desc_req_cb
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
  
  uVar2 = ZDO_INVALID_SHORT_ADDR;
  __dest = malloc(0xd);
  puVar3 = (undefined1 *)zb_buf_begin_func(param_1);
  uVar1 = *puVar3;
  iVar4 = zb_buf_begin_func(param_1);
  if (*(char *)(iVar4 + 1) == '\0') {
    uVar2 = *(undefined2 *)(iVar4 + 2);
    memcpy(__dest,(void *)(iVar4 + 4),0xd);
    zb_schedule_alarm_cancel(node_desc_req_timeout,uVar1,0);
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

