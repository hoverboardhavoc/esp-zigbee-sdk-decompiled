/*
 * Last changed at upstream commit d9ff37b72907da6c3761d958aa9b6c92bf55c912
 * https://github.com/espressif/esp-zigbee-sdk/commit/d9ff37b72907da6c3761d958aa9b6c92bf55c912
 * Upstream date: 2024-10-12 11:34:09 +0800
 * Upstream subject: esp-zigbee-lib:(a9edc7b2)
 * Source: libesp_zb_api_zczr -> esp_zigbee_zdo_command.o -> device_nwk_addr_req_cb
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void device_nwk_addr_req_cb(int param_1)

{
  undefined1 uVar1;
  undefined1 *puVar2;
  int iVar3;
  undefined4 uVar4;
  code *pcVar5;
  undefined2 uStack_22;
  
  if (param_1 == 0) {
    param_1 = zb_assert("/builds/thread_zigbee/esp-zboss/components/esp_zb_sdk/src/esp_zigbee_zdo_command.c"
                        ,0x1ed);
  }
  puVar2 = (undefined1 *)zb_buf_begin_func();
  uVar1 = *puVar2;
  zb_schedule_alarm_cancel(nwk_addr_req_timeout,uVar1,0);
  iVar3 = esp_zb_zdo_callback_find(uVar1);
  if (iVar3 != 0) {
    if (*(char *)(iVar3 + 1) == '\0') {
      pcVar5 = *(code **)(iVar3 + 4);
      uVar4 = *(undefined4 *)(iVar3 + 8);
      esp_zb_zdo_callback_remove(uVar1);
      if (pcVar5 != (code *)0x0) {
        uStack_22 = ZDO_INVALID_SHORT_ADDR;
        if (puVar2[1] == '\0') {
          uStack_22 = *(undefined2 *)(puVar2 + 10);
        }
        (*pcVar5)(uStack_22,uVar4);
      }
    }
    else {
      esp_zb_zdo_callback_remove(uVar1);
    }
  }
  zb_buf_free_func(param_1);
  return;
}

