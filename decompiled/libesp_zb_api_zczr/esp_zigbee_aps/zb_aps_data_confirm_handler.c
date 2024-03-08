/*
 * Last changed at upstream commit 2fe15bae2e4382ac99f249a0934066f5d5a5c684
 * https://github.com/espressif/esp-zigbee-sdk/commit/2fe15bae2e4382ac99f249a0934066f5d5a5c684
 * Upstream date: 2024-03-08 17:10:04 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.0(9d7e9ff2)
 * Source: libesp_zb_api_zczr -> esp_zigbee_aps.o -> zb_aps_data_confirm_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zb_aps_data_confirm_handler(undefined4 param_1)

{
  undefined1 *puVar1;
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
  
  puVar1 = (undefined1 *)zb_buf_get_tail_func(0x19);
  if ((puVar1 != (undefined1 *)0x0) && (s_zb_apsde_data_confirm_handler != (code *)0x0)) {
    uStack_24 = *(undefined4 *)(puVar1 + 2);
    uStack_28 = CONCAT13(puVar1[1],CONCAT12(*puVar1,CONCAT11(puVar1[0x12],puVar1[0x13])));
    uStack_20 = *(undefined4 *)(puVar1 + 6);
    uStack_1c = *(undefined4 *)(puVar1 + 10);
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
  return;
}

