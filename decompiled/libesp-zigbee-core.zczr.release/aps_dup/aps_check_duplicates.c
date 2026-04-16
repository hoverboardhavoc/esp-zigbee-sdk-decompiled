/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> aps_dup.o -> aps_check_duplicates
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

_Bool aps_check_duplicates(aps_header_t *aps_hdr)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  ushort uVar5;
  ezb_shortaddr_t *peVar6;
  uint uVar7;
  ushort uVar8;
  int iVar9;
  uint uVar10;
  int iVar11;
  
  if ((aps_hdr->fcf & 3) == 2) {
    return false;
  }
  if ((aps_hdr->cmd_id != '\x0e') && (1 < (byte)(aps_hdr->cmd_id - 0x11))) {
    iVar2 = core_globals_get();
    bVar1 = aps_hdr->fcf;
    uVar4 = 0;
    while( true ) {
      uVar4 = bitmap_find_next_bit
                        (*(undefined4 *)(iVar2 + 0x988),*(undefined2 *)(iVar2 + 0x98c),uVar4);
      uVar10 = (uint)*(ushort *)(iVar2 + 0x98c);
      iVar9 = *(int *)(iVar2 + 0x984);
      if (uVar10 <= uVar4) break;
      peVar6 = (ezb_shortaddr_t *)(uVar4 * 4 + iVar9);
      if ((((*peVar6 == (aps_hdr->addr_info).src_addr) && ((uint8_t)peVar6[1] == aps_hdr->aps_cntr))
          && ((ushort)((bVar1 & 0xc) == 0) == (peVar6[1] >> 0xe & 1))) &&
         (peVar6[1] >> 0xf == (ushort)((bVar1 & 3) == 1))) {
        return true;
      }
      uVar4 = uVar4 + 1 & 0xffff;
    }
    iVar11 = *(int *)(iVar2 + 0x988);
    do {
      uVar4 = bitmap_find_first_zero_bit(iVar11,uVar10);
      if (uVar10 <= uVar4) goto _L0;
      uVar7 = 1 << (uVar4 & 7) & 0xff;
      uVar3 = __atomic_fetch_or_1((uVar4 >> 3) + iVar11,uVar7,5);
    } while ((uVar7 & uVar3) != 0);
    peVar6 = (ezb_shortaddr_t *)(uVar4 * 4 + iVar9);
    if (peVar6 == (ezb_shortaddr_t *)0x0) {
_L0:
      uVar8 = 0xff;
      uVar4 = 0;
      uVar10 = 0;
      while( true ) {
        uVar10 = bitmap_find_next_bit
                           (*(undefined4 *)(iVar2 + 0x988),*(undefined2 *)(iVar2 + 0x98c),uVar10);
        if (*(ushort *)(iVar2 + 0x98c) <= uVar10) break;
        uVar5 = *(ushort *)(*(int *)(iVar2 + 0x984) + uVar10 * 4 + 2) >> 8 & 0x3f;
        if (uVar5 < uVar8) {
          uVar4 = uVar10;
          uVar8 = uVar5;
        }
        uVar10 = uVar10 + 1 & 0xffff;
      }
      peVar6 = (ezb_shortaddr_t *)(*(int *)(iVar2 + 0x984) + uVar4 * 4);
    }
    *peVar6 = (aps_hdr->addr_info).src_addr;
    *(uint8_t *)(peVar6 + 1) = aps_hdr->aps_cntr;
    *(byte *)((int)peVar6 + 3) =
         ((aps_hdr->fcf & 3) == 1) << 7 | ((aps_hdr->fcf & 0xc) == 0) << 6 | 7U;
    iVar2 = time_ticker_is_receiver_registered(4);
    if (iVar2 == 0) {
      time_ticker_register_receiver(4);
    }
  }
  return false;
}

