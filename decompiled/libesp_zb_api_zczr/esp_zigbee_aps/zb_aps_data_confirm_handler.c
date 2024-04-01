/*
 * Last changed at upstream commit 3128a1de3a8a176dac99e12775a60287e9d10fd7
 * https://github.com/espressif/esp-zigbee-sdk/commit/3128a1de3a8a176dac99e12775a60287e9d10fd7
 * Upstream date: 2024-04-01 17:59:07 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.2(4a0e02cc)
 * Source: libesp_zb_api_zczr -> esp_zigbee_aps.o -> zb_aps_data_confirm_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zb_aps_data_confirm_handler(undefined4 param_1)

{
  void *pvVar1;
  size_t __size;
  void *__src;
  undefined1 auStack_50 [40];
  undefined1 uStack_28;
  undefined1 uStack_27;
  undefined1 auStack_26 [8];
  undefined1 uStack_1e;
  undefined1 uStack_1d;
  undefined4 uStack_1c;
  size_t sStack_18;
  void *pvStack_14;
  
  pvVar1 = (void *)zb_buf_get_tail_func(0x19);
  if ((pvVar1 != (void *)0x0) && (s_zb_apsde_data_confirm_handler != (code *)0x0)) {
    uStack_28 = *(undefined1 *)((int)pvVar1 + 0x13);
    uStack_27 = *(undefined1 *)((int)pvVar1 + 0x12);
    memcpy(auStack_26,pvVar1,8);
    uStack_1e = *(undefined1 *)((int)pvVar1 + 8);
    uStack_1d = *(undefined1 *)((int)pvVar1 + 9);
    uStack_1c = *(undefined4 *)((int)pvVar1 + 10);
    __size = zb_buf_len_func(param_1);
    sStack_18 = __size;
    pvVar1 = malloc(__size);
    pvStack_14 = pvVar1;
    __src = (void *)zb_buf_begin_func(param_1);
    memcpy(pvVar1,__src,__size);
    memcpy(auStack_50,&uStack_28,0x18);
    (*s_zb_apsde_data_confirm_handler)(auStack_50,s_zb_apsde_data_confirm_handler);
    free(pvVar1);
    return;
  }
  return;
}

