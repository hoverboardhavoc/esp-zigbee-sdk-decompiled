/*
 * Last changed at upstream commit e883f431f54d7744605c05ac3bc92898d04315c0
 * https://github.com/espressif/esp-zigbee-sdk/commit/e883f431f54d7744605c05ac3bc92898d04315c0
 * Upstream date: 2025-02-14 17:01:07 +0800
 * Upstream subject: esp-zigbee-sdk: (f9a23626)
 * Source: libesp_zb_api.zczr -> esp_zigbee_aps.o -> zb_aps_data_confirm_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zb_aps_data_confirm_handler(int param_1)

{
  uint uVar1;
  undefined4 uVar2;
  void *pvVar3;
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
  
  if (param_1 == 0) {
    param_1 = zb_assert("/builds/thread_zigbee/esp-zboss/components/esp_zb_sdk/src/aps/esp_zigbee_aps.c"
                        ,0x89);
  }
  uVar1 = zb_buf_layer_get_func();
  if ((uVar1 & 8) != 0) {
    zb_buf_begin_func(param_1);
    uVar2 = zb_aps_full_hdr_size();
    zb_buf_cut_left_func(param_1,uVar2);
    zb_buf_layer_clr_func(param_1,8);
  }
  pvVar3 = (void *)zb_buf_get_tail_func(param_1,0x19);
  if ((pvVar3 != (void *)0x0) && (s_zb_apsde_data_confirm_handler != (code *)0x0)) {
    uStack_28 = *(undefined1 *)((int)pvVar3 + 0x13);
    uStack_27 = *(undefined1 *)((int)pvVar3 + 0x12);
    memcpy(auStack_26,pvVar3,8);
    uStack_1e = *(undefined1 *)((int)pvVar3 + 8);
    uStack_1d = *(undefined1 *)((int)pvVar3 + 9);
    uStack_1c = *(undefined4 *)((int)pvVar3 + 10);
    __size = zb_buf_len_func(param_1);
    sStack_18 = __size;
    pvVar3 = malloc(__size);
    pvStack_14 = pvVar3;
    __src = (void *)zb_buf_begin_func(param_1);
    memcpy(pvVar3,__src,__size);
    memcpy(auStack_50,&uStack_28,0x18);
    (*s_zb_apsde_data_confirm_handler)(auStack_50,s_zb_apsde_data_confirm_handler);
    free(pvVar3);
  }
  zb_buf_free_func(param_1);
  return;
}

