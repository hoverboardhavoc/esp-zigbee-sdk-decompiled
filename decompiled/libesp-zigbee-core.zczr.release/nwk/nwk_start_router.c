/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
 * Source: libesp-zigbee-core.zczr.release -> nwk.o -> nwk_start_router
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int nwk_start_router(void)

{
  char cVar1;
  byte bVar2;
  undefined2 uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  char cStack_1d;
  int iStack_1c;
  undefined4 uStack_18;
  undefined2 uStack_14;
  
  iVar4 = nwk_is_joined();
  if ((iVar4 == 0) || (iVar4 = nwk_is_device_zczr(), iVar4 == 0)) {
    return 0x2c2;
  }
  uStack_18 = 0;
  uStack_14 = 0;
  uVar3 = nwk_get_panid();
  uStack_18 = CONCAT22(uStack_18._2_2_,uVar3);
  bVar2 = nwk_is_device_zc();
  uStack_14 = CONCAT11(uStack_14._1_1_,(byte)uStack_14 & 0xfe | bVar2 & 1);
  uVar5 = nwk_get_pan_channel();
  uStack_18._0_3_ = CONCAT12(0xb,(undefined2)uStack_18);
  uStack_18 = CONCAT13((byte)(uVar5 >> 0x1b),(undefined3)uStack_18);
  uVar5 = uVar5 & 0x7ffffff;
  uVar7 = 0xc;
  uVar6 = 0x1b;
  do {
    if ((uVar5 >> (uVar7 & 0x1f) & 1) == 0) goto _L0;
    uStack_18._0_3_ = CONCAT12((char)uVar7,(undefined2)uStack_18);
    do {
      iVar4 = nwk_mm_start_request(0,&uStack_18);
      if (iVar4 != 0) {
        return iVar4;
      }
      nwk_neighbor_table_restore();
      iVar4 = nwk_is_device_zczr();
      if (iVar4 != 0) {
        iVar4 = core_globals_get();
        *(byte *)(iVar4 + 0xb18) = *(byte *)(iVar4 + 0xb18) | 2;
        iVar4 = core_globals_get();
        cVar1 = *(char *)(iVar4 + 0xa3d);
        iVar4 = core_globals_get();
        cStack_1d = cVar1 + *(char *)(iVar4 + 0xa3e) + '\x0f';
        iStack_1c = core_globals_get();
        uVar7 = 0xa3f;
        iStack_1c = iStack_1c + 0xa3f;
        iVar4 = nwk_mm_set_pib_attr(0xff,0x45,&iStack_1c);
        if ((iVar4 == 0) && (iVar4 = nwk_mm_set_pib_attr(0xff,0x46,&cStack_1d), iVar4 == 0)) {
          nwk_update_beacon_payload();
          iVar4 = core_globals_get();
          if (*(int *)(iVar4 + 0xac4) != 0) {
            iVar4 = core_globals_get();
            *(uint *)(*(int *)(iVar4 + 0xac4) + 0xc) =
                 *(uint *)(*(int *)(iVar4 + 0xac4) + 0xc) & 0xfffffc3f | 0x80;
            iVar4 = core_globals_get();
            *(undefined4 *)(iVar4 + 0xac4) = 0;
          }
          nwk_link_mngr_set_enabled(1);
          time_ticker_register_receiver(1);
          return 0;
        }
      }
      uVar6 = 0;
      uVar5 = __assert_func(0,0,0);
_L0:
      uVar7 = uVar7 + 1;
    } while (uVar7 == uVar6);
  } while( true );
}

