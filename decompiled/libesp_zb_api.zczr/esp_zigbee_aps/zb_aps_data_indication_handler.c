/*
 * Last changed at upstream commit 0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * https://github.com/espressif/esp-zigbee-sdk/commit/0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * Upstream date: 2024-12-06 13:11:49 +0800
 * Upstream subject: esp-zigbee-sdk: (e9475ff2)
 * Source: libesp_zb_api.zczr -> esp_zigbee_aps.o -> zb_aps_data_indication_handler
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
  undefined1 uStack_44;
  undefined1 uStack_43;
  short sStack_42;
  byte bStack_40;
  undefined2 uStack_3e;
  byte bStack_3c;
  undefined2 uStack_3a;
  undefined2 uStack_38;
  size_t sStack_34;
  void *pvStack_30;
  byte bStack_2c;
  uint uStack_28;
  undefined4 uStack_24;
  
  pbVar2 = (byte *)zb_buf_get_tail_func(0x20);
  if (pbVar2 == (byte *)0x0) {
    return 0;
  }
  if (s_zb_apsde_data_ind_handler == (code *)0x0) {
    return 0;
  }
  uStack_44 = 0;
  __size = zb_buf_len_func(param_1);
  __dest = malloc(__size);
  __src = (void *)zb_buf_begin_func(param_1);
  memcpy(__dest,__src,__size);
  pcVar1 = s_zb_apsde_data_ind_handler;
  sStack_42 = *(short *)(pbVar2 + 3);
  bStack_40 = pbVar2[7];
  uStack_3e = *(undefined2 *)(pbVar2 + 1);
  bStack_3c = pbVar2[8];
  uStack_3a = *(undefined2 *)(pbVar2 + 0xb);
  uStack_38 = *(undefined2 *)(pbVar2 + 9);
  uStack_24 = 0;
  bStack_2c = *pbVar2 >> 5 & 1;
  uStack_28 = (uint)pbVar2[0x12];
  if (*(short *)(pbVar2 + 5) == 0) {
    if ((sStack_42 != 0) && (bStack_40 != 0)) {
_L0:
      uStack_43 = 2;
      goto _L0;
    }
  }
  else {
    if (bStack_40 == 0) {
      uStack_43 = 1;
      sStack_42 = *(short *)(pbVar2 + 5);
      goto _L0;
    }
    if (sStack_42 != 0) goto _L0;
  }
  uStack_43 = 0xff;
_L0:
  sStack_34 = __size;
  pvStack_30 = __dest;
  memcpy(auStack_80,&uStack_44,0x24);
  iVar3 = (*pcVar1)(auStack_80);
  free(__dest);
  if (iVar3 == 0) {
    return 0;
  }
  zb_buf_free_func(param_1);
  zb_nwk_unlock_in(param_1);
  return iVar3;
}

