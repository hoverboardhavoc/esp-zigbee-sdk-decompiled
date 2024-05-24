/*
 * Last changed at upstream commit 9b2a25d84666d8bc8515f84abcf92271524d2896
 * https://github.com/espressif/esp-zigbee-sdk/commit/9b2a25d84666d8bc8515f84abcf92271524d2896
 * Upstream date: 2024-05-24 08:27:18 +0000
 * Upstream subject: esp-zigbee-lib:(73447d7e)
 * Source: libesp_zb_api_zczr -> esp_zigbee_aps.o -> zb_aps_data_confirm_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zb_aps_data_confirm_handler(int param_1)

{
  undefined4 uVar1;
  void *pvVar2;
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
                        ,0x82);
  }
  zb_buf_begin_func();
  uVar1 = zb_aps_full_hdr_size();
  zb_buf_cut_left_func(param_1,uVar1);
  pvVar2 = (void *)zb_buf_get_tail_func(param_1,0x19);
  if ((pvVar2 != (void *)0x0) && (s_zb_apsde_data_confirm_handler != (code *)0x0)) {
    uStack_28 = *(undefined1 *)((int)pvVar2 + 0x13);
    uStack_27 = *(undefined1 *)((int)pvVar2 + 0x12);
    memcpy(auStack_26,pvVar2,8);
    uStack_1e = *(undefined1 *)((int)pvVar2 + 8);
    uStack_1d = *(undefined1 *)((int)pvVar2 + 9);
    uStack_1c = *(undefined4 *)((int)pvVar2 + 10);
    __size = zb_buf_len_func(param_1);
    sStack_18 = __size;
    pvVar2 = malloc(__size);
    pvStack_14 = pvVar2;
    __src = (void *)zb_buf_begin_func(param_1);
    memcpy(pvVar2,__src,__size);
    memcpy(auStack_50,&uStack_28,0x18);
    (*s_zb_apsde_data_confirm_handler)(auStack_50,s_zb_apsde_data_confirm_handler);
    free(pvVar2);
  }
  zb_buf_free_func(param_1);
  return;
}

