/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_link_mngr.o -> nwk_link_mngr_send_link_status_cmd
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void nwk_link_mngr_send_link_status_cmd(void)

{
  undefined1 uVar1;
  undefined2 uVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = nwk_is_router_started();
  if (iVar3 == 0) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/nwk/nwk_link_mngr.c",0xea,
                  "nwk_link_mngr_send_link_status_cmd","nwk_is_router_started()");
_L0:
    iVar3 = core_globals_get();
    iVar4 = core_globals_get();
    nwk_link_mngr_start_timer(iVar3 + 0xae4,*(undefined1 *)(iVar4 + 0xa24),0x40);
  }
  else {
    iVar3 = zmsg_alloc(0x27);
    if (iVar3 != 0) {
      iVar4 = core_globals_get();
      uVar1 = *(undefined1 *)(iVar4 + 0xb06);
      iVar4 = core_globals_get();
      uVar2 = *(undefined2 *)(iVar4 + 0xb04);
      iVar4 = core_globals_get();
      uVar2 = nwk_link_mngr_prepare_link_status_command(iVar3,uVar1,uVar2,0x1a);
      *(undefined2 *)(iVar4 + 0xb04) = uVar2;
      nwk_fwd_send_msg_delayed(iVar3,0);
    }
    iVar3 = core_globals_get();
    if (*(short *)(iVar3 + 0xb04) == 0) {
      iVar3 = core_globals_get();
      iVar3 = nwk_mm_get_next_router_iface(iVar3 + 0xb06);
      if (iVar3 != 0) goto _L0;
    }
    iVar3 = core_globals_get();
    nwk_link_mngr_start_timer(iVar3 + 0xae4,0,0x40);
  }
  return;
}

