/*
 * Last changed at upstream commit d4fdccd9eea771602c7571d5f751435deed089e9
 * https://github.com/espressif/esp-zigbee-sdk/commit/d4fdccd9eea771602c7571d5f751435deed089e9
 * Upstream date: 2025-05-21 11:16:30 +0000
 * Upstream subject: esp-zigbee-sdk: (5d895722)
 * Source: libesp_zb_api.zczr.debug -> esp_zigbee_aps.o -> zb_aps_data_confirm_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zb_aps_data_confirm_handler(int param_1)

{
  uint uVar1;
  undefined1 *puVar2;
  void *__dest;
  void *__src;
  undefined4 uVar3;
  undefined4 local_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  size_t sStack_40;
  void *pvStack_3c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  size_t sStack_18;
  void *pvStack_14;
  
  if (param_1 == 0) {
    zb_assert("/builds/thread_zigbee/esp-zboss/components/esp_zb_sdk/src/aps/esp_zigbee_aps.c",0x92)
    ;
  }
  else {
    uVar1 = zb_buf_layer_get_func();
    if ((uVar1 & 8) == 0) goto _L0;
  }
  zb_buf_begin_func(param_1);
  uVar3 = zb_aps_full_hdr_size();
  zb_buf_cut_left_func(param_1,uVar3);
  zb_buf_layer_clr_func(param_1,8);
_L0:
  puVar2 = (undefined1 *)zb_buf_get_tail_func(param_1,0x19);
  if ((puVar2 != (undefined1 *)0x0) && (s_zb_apsde_data_confirm_handler != (code *)0x0)) {
    uStack_24 = *(undefined4 *)(puVar2 + 2);
    uStack_28 = CONCAT13(puVar2[1],CONCAT12(*puVar2,CONCAT11(puVar2[0x12],puVar2[0x13])));
    uStack_20 = *(undefined4 *)(puVar2 + 6);
    uStack_1c = *(undefined4 *)(puVar2 + 10);
    sStack_18 = zb_buf_len_func(param_1);
    __dest = malloc(sStack_18);
    pvStack_14 = __dest;
    __src = (void *)zb_buf_begin_func(param_1);
    memcpy(__dest,__src,sStack_18);
    local_50 = uStack_28;
    uStack_4c = uStack_24;
    uStack_48 = uStack_20;
    uStack_44 = uStack_1c;
    sStack_40 = sStack_18;
    pvStack_3c = pvStack_14;
    (*s_zb_apsde_data_confirm_handler)(&local_50,s_zb_apsde_data_confirm_handler);
    free(pvStack_14);
  }
  zb_buf_free_func(param_1);
  return;
}

