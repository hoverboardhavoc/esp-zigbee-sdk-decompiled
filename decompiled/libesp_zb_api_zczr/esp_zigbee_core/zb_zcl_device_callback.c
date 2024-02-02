/*
 * Last changed at upstream commit 2e2b779251f791b76c34cc582bf68595de9ac19b
 * https://github.com/espressif/esp-zigbee-sdk/commit/2e2b779251f791b76c34cc582bf68595de9ac19b
 * Upstream date: 2024-02-02 22:15:44 +0800
 * Upstream subject: feat(spinel): support zigbee radio spinel
 * Source: libesp_zb_api_zczr -> esp_zigbee_core.o -> zb_zcl_device_callback
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zb_zcl_device_callback(undefined4 param_1)

{
  uint uVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  code *pcVar6;
  
  uVar1 = 0;
  do {
    if (0x1d < uVar1) {
      if (zcl_device_id_cb == (code *)0x0) {
        iVar3 = 0;
      }
      else {
        iVar3 = (*zcl_device_id_cb)(param_1);
      }
_L0:
      if (iVar3 == 0) {
        iVar3 = zb_buf_get_tail_func(param_1,0x38);
        *(undefined4 *)(iVar3 + 8) = 0xffffffff;
        uVar4 = esp_log_timestamp();
        puVar5 = (undefined4 *)zb_buf_get_tail_func(param_1,0x38);
        esp_log_write(2,"ESP_ZIGBEE_CORE",&_LC2,uVar4,"ESP_ZIGBEE_CORE",*puVar5);
      }
      return;
    }
    piVar2 = (int *)zb_buf_get_tail_func(param_1,0x38);
    if (*piVar2 == (&s_device_cb_table)[uVar1 * 2]) {
      pcVar6 = (code *)(&PTR_zcl_default_device_cb_handler_000176e8)[uVar1 * 2];
      iVar3 = zb_buf_get_tail_func(param_1,0x38);
      uVar4 = (*pcVar6)(param_1);
      *(undefined4 *)(iVar3 + 8) = uVar4;
      iVar3 = 1;
      goto _L0;
    }
    uVar1 = uVar1 + 1;
  } while( true );
}

