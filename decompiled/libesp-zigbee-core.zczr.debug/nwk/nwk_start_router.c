/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
 * Source: libesp-zigbee-core.zczr.debug -> nwk.o -> nwk_start_router
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
  byte extraout_var;
  uint uVar5;
  int iVar6;
  int local_20;
  char cStack_19;
  undefined4 uStack_18;
  undefined2 uStack_14;
  
  iVar4 = nwk_is_joined();
  if ((iVar4 == 0) || (iVar4 = nwk_is_device_zczr(), iVar4 == 0)) {
    iVar4 = 0x2c2;
  }
  else {
    uStack_18 = 0;
    uStack_14 = 0;
    uVar3 = nwk_get_panid();
    uStack_18 = CONCAT22(uStack_18._2_2_,uVar3);
    bVar2 = nwk_is_device_zc();
    uStack_14 = CONCAT11(uStack_14._1_1_,(byte)uStack_14 & 0xfe | bVar2 & 1);
    nwk_get_pan_channel();
    uStack_18 = CONCAT13(extraout_var >> 3,CONCAT12(0xb,(undefined2)uStack_18));
    channel_page_get_next_channel((int)&uStack_18 + 2);
    iVar4 = nwk_mm_start_request(0,&uStack_18);
    if (iVar4 == 0) {
      nwk_neighbor_table_restore();
      nwk_set_router_started(1);
      iVar4 = core_globals_get();
      cVar1 = *(char *)(iVar4 + 0xa3d);
      iVar4 = core_globals_get();
      cStack_19 = cVar1 + *(char *)(iVar4 + 0xa3e) + '\x0f';
      local_20 = core_globals_get();
      local_20 = local_20 + 0xa3f;
      iVar4 = nwk_mm_set_pib_attr(0xff,0x45,&local_20);
      if (iVar4 == 0) {
        iVar4 = nwk_mm_set_pib_attr(0xff,0x46,&cStack_19);
        if (iVar4 == 0) {
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
      else {
        __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/nwk/nwk.c",0x2e7,
                      "nwk_start_router","(nwk_mm_set_pib_attr(0xFF, 0x45U, &beacon_payload)) == 0")
        ;
      }
      uVar5 = __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/nwk/nwk.c",0x2e8,
                            "nwk_start_router",
                            "(nwk_mm_set_pib_attr(0xFF, 0x46U, &beacon_payload_length)) == 0");
      iVar4 = core_globals_get();
      iVar6 = iVar4 + 0x1000;
      if (*(byte *)(iVar4 + 0x9df) != uVar5) {
        iVar4 = core_globals_get();
        *(char *)(iVar4 + 0x9df) = (char)uVar5;
        iVar6 = nwk_update_beacon_payload();
      }
      return iVar6;
    }
  }
  return iVar4;
}

