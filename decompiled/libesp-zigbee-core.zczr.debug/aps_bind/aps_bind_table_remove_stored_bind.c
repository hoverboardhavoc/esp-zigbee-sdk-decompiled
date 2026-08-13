/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
 * Source: libesp-zigbee-core.zczr.debug -> aps_bind.o -> aps_bind_table_remove_stored_bind
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void aps_bind_table_remove_stored_bind(int param_1,ushort *param_2)

{
  int iVar1;
  char cVar2;
  uint uStack_28;
  int iStack_24;
  short sStack_20;
  char cStack_1e;
  char cStack_1d;
  uint uStack_1c;
  int iStack_18;
  undefined2 uStack_14;
  char cStack_12;
  
  uStack_14 = 0;
  cStack_12 = '\0';
  ds_bind_info_itor_read(&sStack_20);
  do {
    if (cStack_12 != '\0') {
      return;
    }
    if ((sStack_20 == *(short *)(param_1 + 4)) && (cStack_1e == *(char *)(param_1 + 2))) {
      if ((*(byte *)((int)param_2 + 5) & 1) == 0) {
        cVar2 = (char)param_2[1];
      }
      else {
        cVar2 = '\0';
      }
      if (cStack_1d == cVar2) {
        if ((*(byte *)((int)param_2 + 5) & 1) == 0) {
          iVar1 = nwk_address_extended_by_ref(*param_2,&uStack_28);
          if (iVar1 != 0) {
            __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/aps/aps_bind.c",0x210,
                          "aps_bind_table_remove_stored_bind",
                          "(nwk_address_extended_by_ref(dst->extaddr.addr_ref, &dst_addr)) == 0");
            return;
          }
          if ((uStack_1c == uStack_28) && (iStack_18 == iStack_24)) goto _L0;
        }
        else if ((uStack_1c & 0xffff) == (uint)*param_2) {
_L0:
          ds_bind_info_delete(&sStack_20);
        }
      }
    }
    ds_bind_info_next(&sStack_20);
  } while( true );
}

