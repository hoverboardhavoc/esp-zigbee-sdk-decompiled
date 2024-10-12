/*
 * Last changed at upstream commit d9ff37b72907da6c3761d958aa9b6c92bf55c912
 * https://github.com/espressif/esp-zigbee-sdk/commit/d9ff37b72907da6c3761d958aa9b6c92bf55c912
 * Upstream date: 2024-10-12 11:34:09 +0800
 * Upstream subject: esp-zigbee-lib:(a9edc7b2)
 * Source: libesp_zb_api_zczr.debug -> esp_zigbee_aps.o -> zb_aps_data_confirm_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zb_aps_data_confirm_handler(int param_1)

{
  undefined4 uVar1;
  undefined1 *puVar2;
  void *__dest;
  void *__src;
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
  
  if (param_1 != 0) {
    zb_buf_begin_func();
    uVar1 = zb_aps_full_hdr_size();
    zb_buf_cut_left_func(param_1,uVar1);
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
  uVar1 = zb_assert("/builds/thread_zigbee/esp-zboss/components/esp_zb_sdk/src/aps/esp_zigbee_aps.c"
                    ,0x83);
  zb_aps_set_indication_data_rx_cb(0x10000);
  s_zb_apsde_data_ind_handler = uVar1;
  return;
}

