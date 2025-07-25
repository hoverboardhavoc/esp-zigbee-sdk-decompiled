/*
 * Last changed at upstream commit 232ecc4094b2fa86cc70f7e95820b15daf5d0bff
 * https://github.com/espressif/esp-zigbee-sdk/commit/232ecc4094b2fa86cc70f7e95820b15daf5d0bff
 * Upstream date: 2025-07-25 14:23:12 +0800
 * Upstream subject: esp-zigbee-sdk: (5de57b2b)
 * Source: libesp_zb_api.zczr -> esp_zigbee_test_utils.o -> esp_zb_apsme_remove_device_request
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_zb_apsme_remove_device_request(void *param_1)

{
  int iVar1;
  void *__dest;
  undefined4 uVar2;
  
  iVar1 = zb_buf_get_out_func();
  if (iVar1 == 0) {
    uVar2 = 0x101;
  }
  else {
    __dest = (void *)zb_buf_get_tail_func(0x10);
    memcpy(__dest,param_1,8);
    memcpy((void *)((int)__dest + 8),(void *)((int)param_1 + 8),8);
    zb_schedule_callback(&zb_secur_apsme_remove_device,iVar1);
    uVar2 = 0;
  }
  return uVar2;
}

