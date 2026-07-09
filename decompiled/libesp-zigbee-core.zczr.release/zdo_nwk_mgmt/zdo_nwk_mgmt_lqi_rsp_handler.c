/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> zdo_nwk_mgmt.o -> zdo_nwk_mgmt_lqi_rsp_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 zdo_nwk_mgmt_lqi_rsp_handler(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  byte bStack_2c;
  byte bStack_2b;
  ushort uStack_2a;
  undefined4 uStack_28;
  void *pvStack_24;
  
  uStack_28 = 0;
  pvStack_24 = (void *)0x0;
  if ((param_1 != 0) && (iVar1 = *(int *)(param_1 + 0x14), iVar1 != 0)) {
    uStack_2a = 0;
    uVar4 = zmsg_get_length(iVar1);
    af_read_le8_isra_0(iVar1,&uStack_2a,&uStack_28);
    af_read_le8_isra_0(iVar1,&uStack_2a,(int)&uStack_28 + 1);
    af_read_le8_isra_0(iVar1,&uStack_2a,(int)&uStack_28 + 2);
    af_read_le8_isra_0(iVar1,&uStack_2a,(int)&uStack_28 + 3);
    if (uStack_2a <= uVar4) {
      if (((uStack_28 & 0xff) == 0) && (uStack_28 >> 0x18 != 0)) {
        pvStack_24 = calloc(uStack_28 >> 0x18,0x16);
        uVar3 = 0;
        if (pvStack_24 == (void *)0x0) goto _L0;
        for (; uVar3 < uStack_28 >> 0x18; uVar3 = uVar3 + 1 & 0xff) {
          iVar5 = uVar3 * 0x16;
          bStack_2c = 0;
          bStack_2b = 0;
          af_read_bytes_isra_0(iVar1,&uStack_2a,8,(void *)((int)pvStack_24 + iVar5));
          af_read_bytes_isra_0(iVar1,&uStack_2a,8,(int)pvStack_24 + iVar5 + 8);
          af_read_le16_isra_0(iVar1,&uStack_2a,(int)pvStack_24 + iVar5 + 0x10);
          af_read_le8_isra_0(iVar1,&uStack_2a,&bStack_2c);
          af_read_le8_isra_0(iVar1,&uStack_2a,&bStack_2b);
          af_read_le8_isra_0(iVar1,&uStack_2a,(int)pvStack_24 + iVar5 + 0x14);
          af_read_le8_isra_0(iVar1,&uStack_2a,(int)pvStack_24 + iVar5 + 0x15);
          if (uVar4 < uStack_2a) goto _L0;
          *(ushort *)((int)pvStack_24 + iVar5 + 0x12) =
               bStack_2c & 0x7f | (ushort)((bStack_2b & 3) << 8) |
               *(ushort *)((int)pvStack_24 + iVar5 + 0x12) & 0xfc80;
        }
      }
      zdo_cb_nwk_mgmt_lqi_rsp_isra_0(&uStack_28,param_1 + 8);
      uVar2 = 0;
      goto _L0;
    }
  }
_L0:
  uVar2 = 0xfe;
_L0:
  if (pvStack_24 != (void *)0x0) {
    mm_free();
  }
  return uVar2;
}

