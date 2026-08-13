/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
 * Source: libesp-zigbee-core.zczr.debug -> mac.o -> mac_src_match_remove
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void mac_src_match_remove(int param_1,char *param_2)

{
  undefined4 *unaff_s0;
  int iVar1;
  undefined4 *puVar2;
  int unaff_s5;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined2 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined2 uStack_24;
  
  if ((param_2 != (char *)0x0) && ((byte)(*param_2 - 2U) < 2)) {
    uStack_2c = 0;
    uStack_28 = 0;
    uStack_24 = 0;
    unaff_s0 = *(undefined4 **)(param_1 + 0x60);
    unaff_s5 = 0;
    puVar2 = (undefined4 *)0x0;
    while( true ) {
      if ((undefined4 *)(param_1 + 0x60) == unaff_s0) {
        mac_pal_src_match_remove(param_2);
        iVar1 = mac_src_match_add(param_1,&uStack_2c,puVar2);
        if ((iVar1 == 0) && (unaff_s5 == 0)) {
          mac_pal_src_match_set_enabled(1);
        }
        return;
      }
      zmsg_get_footer(unaff_s0,&uStack_38,10);
      iVar1 = ezb_address_compare(&uStack_38,param_2);
      if (iVar1 != 0) break;
      if ((*(ushort *)((int)unaff_s0 + 0x16) & 0x40) == 0) {
        if (puVar2 == (undefined4 *)0x0) {
_L0:
          uStack_2c = uStack_38;
          uStack_28 = uStack_34;
          uStack_24 = uStack_30;
          puVar2 = unaff_s0;
        }
        else {
          unaff_s5 = 1;
        }
      }
      unaff_s0 = (undefined4 *)*unaff_s0;
    }
    return;
  }
  __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/mac/mac.c",0x74,"mac_src_match_remove",
                "addr && (addr->addr_mode == EZB_ADDR_MODE_SHORT || addr->addr_mode == EZB_ADDR_MODE_EXT)"
               );
  goto _L0;
}

