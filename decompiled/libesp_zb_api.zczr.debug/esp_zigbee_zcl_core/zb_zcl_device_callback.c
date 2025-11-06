/*
 * Last changed at upstream commit ef60059b4d605d61a0103f81567229692f238007
 * https://github.com/espressif/esp-zigbee-sdk/commit/ef60059b4d605d61a0103f81567229692f238007
 * Upstream date: 2025-11-06 11:58:56 +0800
 * Upstream subject: esp-zigbee-sdk: (79cb709a)
 * Source: libesp_zb_api.zczr.debug -> esp_zigbee_zcl_core.o -> zb_zcl_device_callback
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zb_zcl_device_callback(undefined4 param_1)

{
  code *pcVar1;
  bool bVar2;
  int *piVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  
  piVar3 = (int *)zb_buf_get_tail_func(0x38);
  puVar6 = s_device_cb_list;
  do {
    if (puVar6 + -2 == (int *)0xfffffff8) {
      if (*piVar3 == 0) {
        iVar4 = zb_buf_get_tail_func(param_1,0x38);
        uVar5 = zcl_device_attribute_update_handler(param_1);
        *(undefined4 *)(iVar4 + 8) = uVar5;
      }
      else {
        bVar2 = false;
_L0:
        if (!bVar2) {
          iVar4 = 0;
          if (zcl_device_id_cb != (code *)0x0) {
            iVar4 = (*zcl_device_id_cb)(param_1);
          }
          if (iVar4 == 0) {
            iVar4 = zb_buf_get_tail_func(param_1,0x38);
            *(undefined4 *)(iVar4 + 8) = 0xffffffff;
            uVar5 = esp_log_timestamp();
            puVar6 = (undefined4 *)zb_buf_get_tail_func(param_1,0x38);
            esp_log(2,"ESP_ZIGBEE_ZCL_CORE",
                    "W (%lu) %s: Device callback id(0x%x) has not been handled\n",uVar5,
                    "ESP_ZIGBEE_ZCL_CORE",*puVar6);
          }
        }
      }
      return;
    }
    if ((puVar6[-2] == *piVar3) && (pcVar1 = (code *)puVar6[-1], pcVar1 != (code *)0x0)) {
      iVar4 = zb_buf_get_tail_func(param_1,0x38);
      uVar5 = (*pcVar1)(param_1);
      *(undefined4 *)(iVar4 + 8) = uVar5;
      bVar2 = true;
      goto _L0;
    }
    puVar6 = (undefined4 *)*puVar6;
  } while( true );
}

