/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> nwk_ed_mngr.o -> nwk_ed_handle_keepalive_timer
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Removing unreachable block (ram,0x000108e2) */
/* WARNING: Variable defined which should be unmapped: req */
/* WARNING: Unknown calling convention */

void nwk_ed_handle_keepalive_timer(void *ctx)

{
  undefined2 uVar1;
  uint32_t uVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  uint uVar6;
  undefined4 uStack_24;
  nwk_ed_tmo_req_cmd_t req;
  
  iVar3 = core_globals_get();
  if ((*(uint *)(iVar3 + 0xaf8) >> 7 & 1) == 0) {
    return;
  }
  iVar3 = core_globals_get();
  uVar5 = *(uint *)(iVar3 + 0xaf8) & 0x3f;
  if (uVar5 == 0) goto _L0;
  if (uVar5 != 1) {
    do {
      __assert_func(0,0,0,0);
_L0:
      iVar3 = core_globals_get();
    } while (((*(uint *)(iVar3 + 0xaf8) >> 6 & 1) != 0) &&
            (iVar3 = nwk_get_keepalive_mode(), iVar3 != 2));
    iVar3 = zmsg_alloc(0x2f);
    if (iVar3 != 0) {
      nwk_ed_get_timeout();
      zmsg_set_offset(iVar3,0);
      uStack_24 = nwk_get_short_address();
      uVar4 = nwk_get_parent_shortaddr();
      nwk_frame_write_hdr(iVar3,uStack_24,uVar4,1,1,0);
      zmsg_append_bytes(iVar3,1,&stack0xffffffeb);
      zmsg_append_bytes(iVar3,2,&stack0xffffffec);
      nwk_fwd_send_msg(iVar3);
    }
    iVar3 = core_globals_get();
    *(byte *)(iVar3 + 0xaf8) = *(byte *)(iVar3 + 0xaf8) & 0xc0 | 1;
    iVar3 = core_globals_get();
    milli_timer_start(iVar3 + 0xae4,500);
    return;
  }
  iVar3 = core_globals_get();
  milli_timer_stop(iVar3 + 0xae4);
  iVar3 = core_globals_get();
  uVar5 = *(uint *)(iVar3 + 0xaf8) >> 7 & 1;
  if (uVar5 == 0) {
    return;
  }
  iVar3 = core_globals_get();
  if ((*(byte *)(iVar3 + 0xa28) & 1) == 0) {
    iVar3 = core_globals_get();
    if ((*(byte *)(iVar3 + 0xa28) & 2) == 0) {
      iVar3 = core_globals_get();
      if (*(char *)(iVar3 + 0x9ee) != '\0') {
        nwk_pim_stop_poll();
      }
      goto _L0;
    }
    iVar3 = core_globals_get();
    if (*(char *)(iVar3 + 0x9ee) != '\0') {
      nwk_pim_stop_poll();
    }
  }
  else {
    nwk_pim_start_poll();
_L0:
    uVar5 = 0;
  }
  iVar3 = core_globals_get();
  if ((*(byte *)(iVar3 + 0xaf8) & 0x40) != 0) {
    iVar3 = core_globals_get();
    uVar6 = *(uint *)(*(int *)(iVar3 + 0xac4) + 0x18);
    uVar2 = nwk_ed_get_keepalive_interval();
    if (uVar2 / 1000 < (uVar6 & 0xfffff)) {
      uVar2 = nwk_ed_get_keepalive_interval();
      iVar3 = core_globals_get();
      uVar6 = *(uint *)(*(int *)(iVar3 + 0xac4) + 0x18);
      *(uint *)(*(int *)(iVar3 + 0xac4) + 0x18) =
           uVar6 & 0xfff00000 | (uVar6 & 0xfffff) - uVar2 / 1000 & 0xfffff;
      if (uVar5 != 0) goto _L0;
    }
    else {
      nwk_pim_stop_poll();
      uStack_24 = 9;
      uVar1 = nwk_get_parent_shortaddr();
      uVar4 = uStack_24;
      uStack_24._3_1_ = SUB41(uVar4,3);
      uStack_24._0_3_ =
           CONCAT12((char)((ushort)uVar1 >> 8),CONCAT11((char)uVar1,(undefined1)uStack_24));
      nwk_handle_network_status_local(&uStack_24);
    }
    return;
  }
_L0:
  iVar3 = core_globals_get();
  *(byte *)(iVar3 + 0xaf8) = *(byte *)(iVar3 + 0xaf8) & 0xc0;
  iVar3 = core_globals_get();
  uVar2 = nwk_ed_get_keepalive_interval();
  milli_timer_start(iVar3 + 0xae4,uVar2);
  return;
}

