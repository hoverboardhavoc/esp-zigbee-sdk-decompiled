/*
 * Last changed at upstream commit e883f431f54d7744605c05ac3bc92898d04315c0
 * https://github.com/espressif/esp-zigbee-sdk/commit/e883f431f54d7744605c05ac3bc92898d04315c0
 * Upstream date: 2025-02-14 17:01:07 +0800
 * Upstream subject: esp-zigbee-sdk: (f9a23626)
 * Source: libesp_zb_api.zczr -> esp_zigbee_aps.o -> esp_zb_apsme_switch_key_request
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_zb_apsme_switch_key_request(void *param_1)

{
  int iVar1;
  void *__dest;
  undefined4 uVar2;
  
  iVar1 = zb_buf_get_out_func();
  if (iVar1 == 0) {
    uVar2 = 0x101;
  }
  else {
    __dest = (void *)zb_buf_get_tail_func(9);
    memcpy(__dest,param_1,8);
    *(undefined1 *)((int)__dest + 8) = *(undefined1 *)((int)param_1 + 8);
    zb_schedule_callback(&zb_apsme_switch_key_request,iVar1);
    uVar2 = 0;
  }
  return uVar2;
}

