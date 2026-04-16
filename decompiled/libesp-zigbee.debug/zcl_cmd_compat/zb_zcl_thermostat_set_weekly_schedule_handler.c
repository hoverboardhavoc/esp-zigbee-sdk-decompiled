/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee.debug -> zcl_cmd_compat.o -> zb_zcl_thermostat_set_weekly_schedule_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Variable defined which should be unmapped: app_message */
/* WARNING: Unknown calling convention */

void zb_zcl_thermostat_set_weekly_schedule_handler(void *arg,esp_zb_core_action_callback_t cb)

{
  uint uVar1;
  ezb_zcl_status_t eVar2;
  esp_err_t err;
  byte *pbVar3;
  char *pcVar4;
  int iVar5;
  undefined4 local_20;
  esp_zb_zcl_thermostat_weekly_schedule_set_message_t app_message;
  
  app_message.info.status = '\0';
  app_message.info.dst_endpoint = '\0';
  app_message.info.cluster = 0;
                    /* WARNING: Load size is inaccurate */
  local_20 = *arg;
  pcVar4 = *(char **)((int)arg + 0xc);
  if (pcVar4 != (char *)0x0) {
    app_message.trans_status = (uint32_t)*(ushort *)(pcVar4 + 1);
    if ((*(int *)(pcVar4 + 4) != 0) && (*pcVar4 != '\0')) {
      for (uVar1 = 0; pbVar3 = *(byte **)((int)arg + 0xc), uVar1 < *pbVar3;
          uVar1 = uVar1 + 1 & 0xffff) {
        iVar5 = uVar1 * 6;
        app_message.trans_status =
             CONCAT22(*(undefined2 *)(*(int *)(pbVar3 + 4) + iVar5),
                      (undefined2)app_message.trans_status);
        app_message.trans.transition_time =
             *(uint16_t *)(iVar5 + *(int *)(*(int *)((int)arg + 0xc) + 4) + 4);
        app_message._8_2_ = *(undefined2 *)(*(int *)(pbVar3 + 4) + iVar5 + 2);
        if (cb != (esp_zb_core_action_callback_t)0x0) {
          err = (*cb)(ESP_ZB_CORE_THERMOSTAT_WEEKLY_SCHEDULE_SET_CB_ID,&local_20);
          eVar2 = esp_err_to_zcl_status(err);
          *(ezb_zcl_status_t *)((int)arg + 0x10) = eVar2;
        }
      }
    }
  }
  return;
}

