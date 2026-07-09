/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_nlme.o -> nwk_handle_network_status
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void nwk_handle_network_status(int param_1)

{
  short sVar1;
  int iVar2;
  uint uVar3;
  uint auStack_14 [3];
  
  iVar2 = nwk_is_joined();
  if (iVar2 == 0) goto _L0;
  iVar2 = nwk_secur_get_seclevel();
  if (((*(ushort *)(param_1 + 0x16) & 2) != 0) != (iVar2 != 0)) goto _L0;
  auStack_14[0] = 0;
  sVar1 = zmsg_get_offset(param_1);
  zmsg_read_bytes(param_1,sVar1 + 1,4,auStack_14);
  uVar3 = auStack_14[0] & 0xff;
  if (uVar3 == 0xd) {
    nwk_fwd_purge_ex(0xffff,nwk_filter_address_conflict_status,auStack_14);
_L0:
    nwk_handle_network_status_local(auStack_14);
  }
  else if (uVar3 < 0xe) {
    if ((uVar3 < 3) || ((uVar3 - 0xb & 0xff) < 2)) goto _L0;
  }
  else if (uVar3 == 0x13) goto _L0;
_L0:
  if (param_1 == 0) {
    return;
  }
_L0:
  zmsg_free(param_1);
  return;
}

