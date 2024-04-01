/*
 * Last changed at upstream commit 3128a1de3a8a176dac99e12775a60287e9d10fd7
 * https://github.com/espressif/esp-zigbee-sdk/commit/3128a1de3a8a176dac99e12775a60287e9d10fd7
 * Upstream date: 2024-04-01 17:59:07 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.2(4a0e02cc)
 * Source: libesp_zb_api_zczr -> esp_zigbee_aps.o -> zb_aps_data_indication_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int zb_aps_data_indication_handler(undefined4 param_1)

{
  code *pcVar1;
  byte *pbVar2;
  size_t __size;
  void *__dest;
  void *__src;
  int iVar3;
  undefined1 auStack_80 [60];
  undefined1 auStack_44 [2];
  undefined2 uStack_42;
  byte bStack_40;
  undefined2 uStack_3e;
  byte bStack_3c;
  undefined2 uStack_3a;
  undefined2 uStack_38;
  size_t sStack_34;
  void *pvStack_30;
  byte bStack_2c;
  uint uStack_28;
  
  pbVar2 = (byte *)zb_buf_get_tail_func(0x20);
  if ((pbVar2 != (byte *)0x0) && (s_zb_apsde_data_ind_handler != (code *)0x0)) {
    auStack_44[0] = 0;
    __size = zb_buf_len_func(param_1);
    __dest = malloc(__size);
    __src = (void *)zb_buf_begin_func(param_1);
    memcpy(__dest,__src,__size);
    pcVar1 = s_zb_apsde_data_ind_handler;
    uStack_42 = *(undefined2 *)(pbVar2 + 3);
    bStack_40 = pbVar2[7];
    uStack_3e = *(undefined2 *)(pbVar2 + 1);
    bStack_3c = pbVar2[8];
    uStack_3a = *(undefined2 *)(pbVar2 + 0xb);
    uStack_38 = *(undefined2 *)(pbVar2 + 9);
    bStack_2c = *pbVar2 >> 5 & 1;
    uStack_28 = (uint)pbVar2[0x12];
    sStack_34 = __size;
    pvStack_30 = __dest;
    memcpy(auStack_80,auStack_44,0x24);
    iVar3 = (*pcVar1)(auStack_80);
    free(__dest);
    if (iVar3 != 0) {
      zb_buf_free_func(param_1);
      zb_nwk_unlock_in(param_1);
      return iVar3;
    }
  }
  return 0;
}

