/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> aps_retrans.o -> aps_reasm_handle_frag
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void aps_reasm_handle_frag(aps_header_t *aps_hdr,zmsg_t *msg)

{
  byte bVar1;
  int iVar2;
  aps_reasm_ent_t *ent;
  
  if ((char)aps_hdr->fcf < '\0') {
    bVar1 = (aps_hdr->ext_hdr).block_nr;
    if (bVar1 != 0) {
      if ((((aps_hdr->ext_hdr).ext_fcf & 3) != 2) && (bVar1 < 2)) goto _L0;
      if ((aps_hdr->fcf & 3) == 0) {
        iVar2 = core_globals_get();
        ent = aps_reasm_ent_find((aps_rx_context_t *)(iVar2 + 0x458),(aps_hdr->addr_info).src_addr,
                                 aps_hdr->aps_cntr);
        if (ent != (aps_reasm_ent_t *)0x0) {
_L0:
          aps_reasm_ent_input(ent,aps_hdr,msg);
          return;
        }
        iVar2 = core_globals_get();
        ent = aps_reasm_ent_new((aps_rx_context_t *)(iVar2 + 0x458));
        if (ent != (aps_reasm_ent_t *)0x0) {
          iVar2 = core_globals_get();
          aps_reasm_ent_init(ent,*(uint8_t *)(iVar2 + 2));
          ent->src_addr = (aps_hdr->addr_info).src_addr;
          ent->aps_cntr = aps_hdr->aps_cntr;
          aps_rx_window_init(&ent->w,(ent->w).slot_nr);
          milli_timer_start(&ent->tm,0x640);
          goto _L0;
        }
      }
    }
    if (msg != (zmsg_t *)0x0) {
      zmsg_free(msg);
    }
  }
  else {
    __assert_func("//build/esp-zigbee/src/core/aps/aps_retrans.c",0x25b,"aps_reasm_handle_frag",
                  "aps_fcf_has_ext_hdr(aps_hdr->fcf)");
_L0:
    aps_handle_datagram();
  }
  return;
}

