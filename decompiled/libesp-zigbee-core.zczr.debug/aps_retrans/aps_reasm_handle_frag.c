/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
 * Source: libesp-zigbee-core.zczr.debug -> aps_retrans.o -> aps_reasm_handle_frag
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void aps_reasm_handle_frag(undefined2 *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  if ((char)*(byte *)(param_1 + 6) < '\0') {
    if (*(byte *)(param_1 + 9) != 0) {
      if (((*(byte *)((int)param_1 + 0x11) & 3) != 2) && (*(byte *)(param_1 + 9) < 2)) goto _L0;
      if ((*(byte *)(param_1 + 6) & 3) == 0) {
        iVar1 = core_globals_get();
        iVar1 = aps_reasm_ent_find(iVar1 + 0x458,*param_1,*(undefined1 *)((int)param_1 + 0xd));
        if (iVar1 != 0) {
_L0:
          aps_reasm_ent_input(iVar1,param_1,param_2);
          return;
        }
        iVar1 = core_globals_get();
        iVar1 = aps_reasm_ent_new(iVar1 + 0x458);
        if (iVar1 != 0) {
          iVar2 = core_globals_get();
          aps_reasm_ent_init(iVar1,*(undefined1 *)(iVar2 + 2));
          *(undefined2 *)(iVar1 + 0xc) = *param_1;
          *(undefined1 *)(iVar1 + 0xe) = *(undefined1 *)((int)param_1 + 0xd);
          aps_rx_window_init(iVar1 + 0x21,*(undefined1 *)(iVar1 + 0x24));
          milli_timer_start(iVar1 + 0x10,0x640);
          goto _L0;
        }
      }
    }
    if (param_2 != 0) {
      zmsg_free(param_2);
    }
  }
  else {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/aps/aps_retrans.c",0x25d,
                  "aps_reasm_handle_frag","aps_fcf_has_ext_hdr(aps_hdr->fcf)");
_L0:
    aps_handle_datagram();
  }
  return;
}

