with import <nixpkgs> {};
{
  env = stdenv.mkDerivation {
    name = "TheAdventuresOfBlinky";
    buildInputs = [
      cmake
      gcc
      git
      less
      sfml
      openssh
      stdenv
      vim
    ];
    SSL_CERT_FILE="/etc/ssl/certs/ca-bundle.crt";
    shellHook = ''
    export PS1="TheAdventuresOfBlinky:[\W] "
    '';
    };
    }
