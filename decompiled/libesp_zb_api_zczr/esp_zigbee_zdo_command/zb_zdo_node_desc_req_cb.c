/*
 * Last changed at upstream commit 503c5e49627f84174ce142bf784c3f01532fb5c9
 * https://github.com/espressif/esp-zigbee-sdk/commit/503c5e49627f84174ce142bf784c3f01532fb5c9
 * Upstream date: 2023-06-05 10:37:46 +0800
 * Upstream subject: esp-zigbee-sdk: optimize the zigbee cluster implementation(0f0acd4)
 * Source: libesp_zb_api_zczr -> esp_zigbee_zdo_command.o -> zb_zdo_node_desc_req_cb
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zb_zdo_node_desc_req_cb(int param_1)

{
  undefined1 uVar1;
  void *__ptr;
  undefined1 *puVar2;
  int iVar3;
  int iVar4;
  undefined2 uVar5;
  
  uVar5 = ZDO_INVALID_SHORT_ADDR;
  __ptr = malloc(0xd);
  puVar2 = (undefined1 *)zb_buf_begin_func(param_1);
  uVar1 = *puVar2;
  iVar3 = zb_buf_begin_func(param_1);
  if (*(char *)(iVar3 + 1) == '\0') {
    uVar5 = *(undefined2 *)(iVar3 + 2);
    __ptr = (void *)(iVar3 + 4);
    iVar4 = zb_schedule_alarm_cancel(node_desc_req_timeout,0xff,0);
    if (iVar4 == 0) goto _L0;
    iVar4 = _esp_error_check_failed
                      ("/home/xieqinan/ESP/esp-zboss/components/esp_zb_sdk/src/esp_zigbee_zdo_command.c"
                       ,0x171,"zb_zdo_node_desc_req_cb",
                       "ZB_SCHEDULE_APP_ALARM_CANCEL(node_desc_req_timeout, ZB_ALARM_ANY_PARAM)");
  }
  else {
_L0:
    iVar4 = esp_zb_zdo_callback_find(uVar1);
    if ((iVar4 == 0) || (*(char *)(iVar4 + 1) != '\x02')) goto _L0;
  }
  if (*(code **)(iVar4 + 4) != (code *)0x0) {
    (**(code **)(iVar4 + 4))(*(undefined1 *)(iVar3 + 1),uVar5,__ptr,*(undefined4 *)(iVar4 + 8));
  }
_L0:
  esp_zb_zdo_callback_remove(uVar1);
  if (param_1 != 0) {
    zb_buf_free_func(param_1);
  }
  free(__ptr);
  return;
}

